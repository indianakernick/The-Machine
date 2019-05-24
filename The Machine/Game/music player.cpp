//
//  music player.cpp
//  The Machine
//
//  Created by Indi Kernick on 15/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "music player.hpp"

#include <cassert>
#include <fstream>
#include <iostream>
#include <Simpleton/Data/json.hpp>
#include <Simpleton/SDL/error.hpp>
#include <Simpleton/SDL/paths.hpp>
#include <Simpleton/Utils/profiler.hpp>

#ifdef NO_EMSCRIPTEN

namespace {
  MusicPlayer *player = nullptr;
  
  void finishCallback() {
    player->nextSong();
  }
}

#else

namespace {
  void audioCallback(void *userdata, Uint8 *stream, int len) {
    reinterpret_cast<MusicPlayer *>(userdata)->fillAudioBuffer(stream, len);
  }
}

#endif

void MusicPlayer::init() {
  PROFILE(MusicPlayer::init);
  
  #ifdef NO_EMSCRIPTEN
  const int flags = MIX_INIT_OGG;
  const int actual = Mix_Init(flags);
  std::cout << "Requested: " << flags << '\n';
  std::cout << "Actual:    " << actual << '\n';
  if (flags != actual) {
    std::cout << "Error: " <<  SDL_GetError() << '\n';
  }
  //CHECK_SDL_ERROR(Mix_Init(MIX_INIT_OGG) != MIX_INIT_OGG ? -1 : 0);
  #endif
  
  loadMusic();
  initRNG();
  shuffle();
  openAudio();
  printSong();
}

void MusicPlayer::quit() {
  closeAudio();
  for (const Song &song : songs) {
    #ifdef NO_EMSCRIPTEN
    Mix_FreeMusic(song.music);
    #else
    stb_vorbis_close(song.music);
    #endif
  }
  songs.clear();
  
  #ifdef NO_EMSCRIPTEN
  Mix_Quit();
  #endif
}

void MusicPlayer::togglePlaying() {
  #ifdef NO_EMSCRIPTEN
  
  if (Mix_PausedMusic()) {
    Mix_ResumeMusic();
  } else {
    Mix_PauseMusic();
  }
  
  #else
  
  const SDL_AudioStatus status = SDL_GetAudioDeviceStatus(audioDevice);
  if (status != SDL_AUDIO_PLAYING) {
    SDL_PauseAudioDevice(audioDevice, 0);
  } else {
    SDL_PauseAudioDevice(audioDevice, 1);
  }
  
  #endif
}

void MusicPlayer::nextSong() {
  if (++currentSong == songs.size()) {
    currentSong = 0;
    shuffle();
  }
  printSong();
}

#ifndef NO_EMSCRIPTEN

void MusicPlayer::fillAudioBuffer(uint8_t *const buffer, const int requestedBytes) {
  if (!songs.empty()) {
    constexpr int bytesPerSample = 4;
    constexpr int channels = 2;
  
    stb_vorbis *music = songs[currentSong].music;
    const int requestedSamples = requestedBytes / bytesPerSample;
    const int obtainedSamples = channels * stb_vorbis_get_samples_float_interleaved(
      music,
      channels,
      reinterpret_cast<float *>(buffer),
      requestedSamples
    );
    if (obtainedSamples < requestedSamples) {
      stb_vorbis_seek_start(music);
      nextSong();
      const int obtainedBytes = obtainedSamples * bytesPerSample;
      fillAudioBuffer(buffer + obtainedBytes, requestedBytes - obtainedBytes);
    }
  }
}

#endif

void MusicPlayer::loadMusic() {
  const std::string resDir = SDL::getResDir();
  std::ifstream musicFile(resDir + "music.json");
  json musicData;
  musicFile >> musicData;
  
  for (json &songNode : musicData) {
    Song song;
    Data::get(song.name, songNode, "name");
    Data::get(song.artist, songNode, "artist");
    const std::string songFileName = resDir + songNode.at("file").get<std::string>();
    
    #ifdef NO_EMSCRIPTEN
    
    song.music = CHECK_SDL_NULL(Mix_LoadMUS(songFileName.c_str()));
    
    #else
    
    int error;
    song.music = stb_vorbis_open_filename(songFileName.c_str(), &error, nullptr);
    if (song.music == nullptr) {
      if (error == VORBIS_file_open_failure) {
        std::cout << "File does not exist: " << songFileName << '\n';
      } else if (error >= VORBIS_unexpected_eof) {
        std::cout << "File is currupt: " << songFileName << '\n';
      } else {
        std::cout << "Something weird happened, you might want to look into this\n";
        assert(false);
      }
    }
    
    #endif
    
    songs.emplace_back(std::move(song));
  }
}

void MusicPlayer::initRNG() {
  std::random_device device;
  gen = decltype(gen)(device());
}

void MusicPlayer::shuffle() {
  std::shuffle(songs.begin(), songs.end(), gen);
}

void MusicPlayer::openAudio() {
  #ifdef NO_EMSCRIPTEN
  
  CHECK_SDL_ERROR(Mix_OpenAudio(
    44100,
    MIX_DEFAULT_FORMAT,
    2,
    4096
  ));
  player = this;
  Mix_HookMusicFinished(&finishCallback);
  CHECK_SDL_ERROR(Mix_PlayMusic(songs[0].music, 1));

  #else
  
  SDL_AudioSpec desired;
  desired.freq = 44100;
  desired.format = AUDIO_F32SYS;
  desired.channels = 2;
  desired.samples = 4096;
  desired.callback = &audioCallback;
  desired.userdata = this;
  audioDevice = SDL_OpenAudioDevice(
    nullptr,
    0,
    &desired,
    nullptr,
    0
  );
  
  SDL_PauseAudioDevice(audioDevice, 0);
  
  #endif
}

void MusicPlayer::closeAudio() {
  #ifdef NO_EMSCRIPTEN
  
  Mix_CloseAudio();
  
  #else
  
  SDL_CloseAudioDevice(audioDevice);
  audioDevice = 0;
  
  #endif
}

void MusicPlayer::printSong() {
  if (!songs.empty()) {
    const Song &song = songs[currentSong];
    std::cout << "Currently playing " << song.artist << " - " << song.name << '\n';
  }
}
