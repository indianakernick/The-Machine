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

  static constexpr size_t NUM_SONGS = 10;

  void init();
  void quit();
  
  void togglePlaying();
  
private:
  std::vector<SDL::Music> songs;
  size_t currentSong = 0;
  std::mt19937 gen;
};

#endif
