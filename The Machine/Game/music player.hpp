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
#include "stb_vorbis.h"
#include <SDL2/SDL_audio.h>
#include <Simpleton/Utils/instance limiter.hpp>

class MusicPlayer final : public Utils::ForceSingleton<MusicPlayer> {
public:
  void init();
  void quit();
  
  void togglePlaying();
  
  void nextSong();
  void fillAudioBuffer(uint8_t *, int);
  
private:
  struct Song {
    std::string name;
    std::string artist;
    stb_vorbis *music;
  };

  std::vector<Song> songs;
  size_t currentSong = 0;
  std::mt19937 gen;
  SDL_AudioDeviceID audioDevice = 0;
  
  void loadMusic();
  void initRNG();
  void shuffle();
  void openAudio();
  void closeAudio();
  void printSong();
};

#endif
