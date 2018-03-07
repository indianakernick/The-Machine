//
//  music player.cpp
//  The Machine
//
//  Created by Indi Kernick on 15/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "music player.hpp"

#ifdef EMSCRIPTEN

void MusicPlayer::init() {};
    void MusicPlayer::quit() {};

    void MusicPlayer::togglePlaying() {};

    void MusicPlayer::nextSong() {};
    void MusicPlayer::fillAudioBuffer(uint8_t *, int) {};

#else

#include <cassert>
#include <fstream>
#include <iostream>
#include <Simpleton/Data/json.hpp>
#include <Simpleton/SDL/paths.hpp>
#include <Simpleton/Utils/profiler.hpp>

namespace {
  void audioCallback(void *userdata, Uint8 *stream, int len) {
    reinterpret_cast<MusicPlayer *>(userdata)->fillAudioBuffer(stream, len);
  }
}

void MusicPlayer::init() {
  PROFILE(MusicPlayer::init);
  
  loadMusic();
  initRNG();
  shuffle();
  openAudio();
  printSong();
}

void MusicPlayer::quit() {
  closeAudio();
  for (const Song &song : songs) {
    stb_vorbis_close(song.music);
  }
  songs.clear();
}

void MusicPlayer::togglePlaying() {
  const SDL_AudioStatus status = SDL_GetAudioDeviceStatus(audioDevice);
  if (status != SDL_AUDIO_PLAYING) {
    SDL_PauseAudioDevice(audioDevice, 0);
  } else {
    SDL_PauseAudioDevice(audioDevice, 1);
  }
}

void MusicPlayer::nextSong() {
  if (++currentSong == songs.size()) {
    currentSong = 0;
    shuffle();
  }
  printSong();
}

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
}

void MusicPlayer::closeAudio() {
  SDL_CloseAudioDevice(audioDevice);
  audioDevice = 0;
}

void MusicPlayer::printSong() {
  if (!songs.empty()) {
    const Song &song = songs[currentSong];
    std::cout << "Currently playing " << song.artist << " - " << song.name << '\n';
  }
}

#endif