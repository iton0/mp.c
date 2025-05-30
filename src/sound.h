// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#ifndef SOUND_H_
#define SOUND_H_

#include <raylib.h>
#include <stdint.h>

void add_sound(const char *file, Sound *sounds, const uint8_t idx);
void remove_sound(Sound *sounds, const uint8_t idx);
void play_sound(const Sound *sounds, const uint8_t idx);
void play_pressed_sounds(const Sound *sounds, const bool *pressed_keys);

#endif
