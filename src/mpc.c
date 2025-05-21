// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "mpc.h"
#include "color.h"
#include "display.h"
#include "key.h"
#include "setting.h"
#include "sound.h"

int run_mpc(void) {
  const uint8_t PAD_KEYS[GRID_TOTAL] = {
      KEY_Q, KEY_W, KEY_E, KEY_R, // row 1
      KEY_A, KEY_S, KEY_D, KEY_F, // row 2
      KEY_Z, KEY_X, KEY_C, KEY_V, // row 3
      KEY_U, KEY_I, KEY_O, KEY_P, // row 4
  };
  const int FPS = 30;
  Sound sounds[GRID_TOTAL] = {0};
  bool pressed_keys[GRID_TOTAL] = {false};
  int screen_width = 1280;
  int screen_height = 1024;

  if (!ChangeDirectory(GetApplicationDirectory())) {
    return -1; // unsuccessful directory change
  }

  InitWindow(screen_width, screen_height, "Mp.c");
  SetWindowMinSize(screen_width, screen_height);
  SetTargetFPS(FPS);
  InitAudioDevice();

  while (!WindowShouldClose()) {
    // update variables here
    screen_width = GetScreenWidth();
    screen_height = GetScreenHeight();
    const pad_ui_data PAD_UI_DATA =
        update_pad_ui_data(screen_width, screen_height);
    const display_ui_data DISPLAY_UI_DATA =
        update_display_ui_data(PAD_UI_DATA, screen_height);
    const setting_ui_data SETTING_UI_DATA =
        update_setting_ui_data(DISPLAY_UI_DATA);

    update_pressed_keys(pressed_keys, PAD_KEYS);

    // drawing
    BeginDrawing();
    ClearBackground(MPC_BG_COLOR);

    play_pressed_sounds(sounds, pressed_keys);

    draw_pad(PAD_UI_DATA, pressed_keys);
    draw_display(DISPLAY_UI_DATA);
    draw_settings(SETTING_UI_DATA);

    EndDrawing();
  }

  CloseAudioDevice();
  CloseWindow();

  return 0;
}
