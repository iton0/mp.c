// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "key.h"
#include "pad.h"
#include "sound.h"
#include "util.h"

int main(void) {
  const int SCREEN_WIDTH = 1250, SCREEN_HEIGHT = 950, FPS = 30;
  const uint8_t PAD_KEYS[GRID_TOTAL] = {
      KEY_Q, KEY_W, KEY_E, KEY_R, // row 1
      KEY_A, KEY_S, KEY_D, KEY_F, // row 2
      KEY_Z, KEY_X, KEY_C, KEY_V, // row 3
      KEY_U, KEY_I, KEY_O, KEY_P, // row 4
  };
  // TODO: should i keep sounds array of type Sounds or filename?
  Sound sounds[GRID_TOTAL] = {0};
  bool pressed_keys[GRID_TOTAL] = {false};

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mp.c");
  SetTargetFPS(FPS);
  InitAudioDevice();

  while (!WindowShouldClose()) {
    // update variables here
    update_pressed_keys(pressed_keys, PAD_KEYS);

    // drawing
    BeginDrawing();
    ClearBackground(RAYWHITE);

    draw_pad(pressed_keys);
    play_pressed_sounds(sounds, pressed_keys);

    EndDrawing();
  }

  CloseAudioDevice();
  CloseWindow();

  return 0;
}
