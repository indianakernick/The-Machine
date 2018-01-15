//
//  music player.cpp
//  The Machine
//
//  Created by Indi Kernick on 15/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "music player.hpp"

#include <cassert>
#include <Simpleton/Utils/profiler.hpp>
#include <Simpleton/SDL/paths.hpp>

namespace {
  MusicPlayer *globalPlayer = nullptr;
}

void songFinished() {
  assert(globalPlayer);
  if (++globalPlayer->currentSong == globalPlayer->songs.size()) {
    globalPlayer->currentSong = 0;
    std::shuffle(globalPlayer->songs.begin(), globalPlayer->songs.end(), globalPlayer->gen);
  }
  globalPlayer->songs[globalPlayer->currentSong].play();
}

void MusicPlayer::init() {
  PROFILE(MusicPlayer::init);
  const std::string resDir = SDL::getResDir();
  
  for (size_t i = 0; i != NUM_SONGS; ++i) {
    const std::string path = resDir + std::to_string(i + 1) + ".wav";
    songs.emplace_back(SDL::makeMusic(path.c_str()));
  }
  
  std::random_device device;
  gen = decltype(gen)(device());
  
  std::shuffle(songs.begin(), songs.end(), gen);
  
  assert(globalPlayer == nullptr);
  globalPlayer = this;
  
  Mix_HookMusicFinished(&songFinished);
  
  if (!songs.empty()) {
    songs[0].play();
  }
}

void MusicPlayer::quit() {
  songs.clear();
}

void MusicPlayer::togglePlaying() {
  if (Mix_PausedMusic()) {
    Mix_ResumeMusic();
  } else {
    Mix_PauseMusic();
  }
}
