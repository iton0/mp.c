// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "display.h"
#include "key.h"
#include "sound.h"

int main(void) {
  const int FPS = 30;
  const uint8_t PAD_KEYS[GRID_TOTAL] = {
      KEY_Q, KEY_W, KEY_E, KEY_R, // row 1
      KEY_A, KEY_S, KEY_D, KEY_F, // row 2
      KEY_Z, KEY_X, KEY_C, KEY_V, // row 3
      KEY_U, KEY_I, KEY_O, KEY_P, // row 4
  };
  Sound sounds[GRID_TOTAL] = {0};
  bool pressed_keys[GRID_TOTAL] = {false};
  int screen_width = 1280;
  int screen_height = 1024;

  InitWindow(screen_width, screen_height, "Mp.c");
  SetWindowMinSize(screen_width, screen_height);
  SetTargetFPS(FPS);
  InitAudioDevice();

  do {
    // update variables here
    const pad_ui_data PAD_UI_DATA =
        update_pad_ui_data(screen_width, screen_height);
    const display_ui_data DISPLAY_UI_DATA =
        update_display_ui_data(PAD_UI_DATA, screen_height);

    // drawing
    BeginDrawing();
    ClearBackground(RAYWHITE);

    play_pressed_sounds(sounds, pressed_keys);

    draw_pad(PAD_UI_DATA, pressed_keys);
    draw_display(DISPLAY_UI_DATA);

    EndDrawing();

    update_pressed_keys(pressed_keys, PAD_KEYS);
    screen_width = GetScreenWidth();
    screen_height = GetScreenHeight();
  } while (!WindowShouldClose());

  CloseAudioDevice();
  CloseWindow();

  return 0;
}
