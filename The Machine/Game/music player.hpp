//
//  music player.hpp
//  The Machine
//
//  Created by Indi Kernick on 15/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef music_player_hpp
#define music_player_hpp

#include <vector>
#include <random>
#include <Simpleton/Utils/instance limiter.hpp>

#ifdef NO_EMSCRIPTEN

#include <SDL2/SDL_mixer.h>

#else

#include "stb_vorbis.h"
#include <SDL2/SDL_audio.h>

#endif

class MusicPlayer final : public Utils::ForceSingleton<MusicPlayer> {
public:
  void init();
  void quit();
  
  void togglePlaying();
  
  void nextSong();
  
  #ifndef NO_EMSCRIPTEN
  void fillAudioBuffer(uint8_t *, int);
  #endif
  
private:
  struct Song {
    std::string name;
    std::string artist;
    #ifdef NO_EMSCRIPTEN
    Mix_Music *music;
    #else
    stb_vorbis *music;
    #endif
  };

  std::vector<Song> songs;
  size_t currentSong = 0;
  std::mt19937 gen;
  #ifndef NO_EMSCRIPTEN
  SDL_AudioDeviceID audioDevice = 0;
  #endif
  
  void loadMusic();
  void initRNG();
  void shuffle();
  void openAudio();
  void closeAudio();
  void printSong();
};

#endif
