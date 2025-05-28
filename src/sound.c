// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "sound.h"
#include "util.h"

void add_sound(const char *file, Sound *sounds, const uint8_t idx) {
  sounds[idx] = LoadSound(file);
}

void remove_sound(Sound *sounds, const uint8_t idx) {
  UnloadSound(sounds[idx]);
  sounds[idx] = (Sound){0};
}

void play_sound(const Sound *sounds, const uint8_t idx) {
  const Sound sound = sounds[idx];
  if (IsSoundPlaying(sound)) {
    StopSound(sound);
  }
  PlaySound(sound);
}

void play_pressed_sounds(const Sound *sounds, const bool *pressed_keys) {
  for (uint8_t i = 0; i < GRID_TOTAL; ++i) {
    // TODO: update to account when key is held down; should not play sound
    if (pressed_keys[i]) {
      play_sound(sounds, i);
    }
  }
}
