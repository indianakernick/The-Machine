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
#include <Simpleton/SDL/music.hpp>
#include <Simpleton/Utils/instance limiter.hpp>

void songFinished();

class MusicPlayer final : public Utils::ForceSingleton<MusicPlayer> {
public:
  friend void songFinished();

  void init();
  void quit();
  
  void togglePlaying();
  
private:
  struct Song {
    std::string name;
    std::string artist;
    SDL::Music music;
  };

  std::vector<Song> songs;
  size_t currentSong = 0;
  std::mt19937 gen;
  
  void loadMusic();
  void initRNG();
  void shuffle();
  void setFinishHook();
  void removeFinishHook();
  void songFinished();
};

#endif
