// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#ifndef SOUND_H_
#define SOUND_H_

#include <raylib.h>

// TODO: what other functions do i need for sound
void add_sound(const char *file);
void remove_sound(Sound sound);
void play_sound(const Sound sound);

#endif
