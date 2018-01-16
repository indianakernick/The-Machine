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
#include <Simpleton/Data/json.hpp>
#include <Simpleton/SDL/paths.hpp>
#include <Simpleton/Utils/profiler.hpp>

namespace {
  MusicPlayer *globalPlayer = nullptr;
  
  void songFinished() {
    assert(globalPlayer);
    globalPlayer->nextSong();
  }
}

void MusicPlayer::init() {
  PROFILE(MusicPlayer::init);
  
  loadMusic();
  initRNG();
  shuffle();
  setFinishHook();
  
  if (!songs.empty()) {
    songs[0].music.play();
  }
}

void MusicPlayer::quit() {
  removeFinishHook();
  songs.clear();
}

void MusicPlayer::togglePlaying() {
  if (Mix_PausedMusic()) {
    Mix_ResumeMusic();
  } else {
    Mix_PauseMusic();
  }
}

void MusicPlayer::nextSong() {
  if (++currentSong == songs.size()) {
    currentSong = 0;
    shuffle();
  }
  songs[currentSong].music.play();
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
    const std::string songFileName = songNode.at("file").get<std::string>();
    song.music = SDL::makeMusic((resDir + songFileName).c_str());
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

void MusicPlayer::setFinishHook() {
  assert(globalPlayer == nullptr);
  globalPlayer = this;
  Mix_HookMusicFinished(&songFinished);
}

void MusicPlayer::removeFinishHook() {
  assert(globalPlayer == this);
  Mix_HookMusicFinished(nullptr);
  globalPlayer = nullptr;
}
