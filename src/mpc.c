// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "mpc.h"
#include "color.h"
#include "display.h"
#include "info.h"
#include "key.h"
#include "setting.h"
#include "sound.h"

#include <string.h>

int run_mpc(void) {
  if (!ChangeDirectory(GetApplicationDirectory())) {
    return -1; // unsuccessful directory change
  }

  const uint8_t PAD_KEYS[GRID_TOTAL] = {
      KEY_Q, KEY_W, KEY_E, KEY_R, // row 1
      KEY_A, KEY_S, KEY_D, KEY_F, // row 2
      KEY_Z, KEY_X, KEY_C, KEY_V, // row 3
      KEY_U, KEY_I, KEY_O, KEY_P, // row 4
  };
  const char *INFO_DATA[DISPLAY_ROWS] = {NULL};
  const int FPS = 30;
  Sound sounds[GRID_TOTAL] = {0};
  bool pressed_pad_keys[GRID_TOTAL] = {false};
  int screen_width = 1280;
  int screen_height = 1024;

  InitWindow(screen_width, screen_height, "MP.c");
  SetWindowMinSize(screen_width, screen_height);
  SetTargetFPS(FPS);
  InitAudioDevice();

  // TODO: remove once dynamic selection functionality works
  add_sound("assets/audio/test-piano.wav", sounds, 0);
  add_sound("assets/audio/test-melody.wav", sounds, 1);
  add_sound("assets/audio/test-pad.wav", sounds, 2);

  while (!WindowShouldClose()) {
    // update variables here
    screen_width = GetScreenWidth();
    screen_height = GetScreenHeight();
    const pad_ui_data PAD_UI_DATA =
        update_pad_ui_data(screen_width, screen_height);
    const display_ui_data DISPLAY_UI_DATA =
        update_display_ui_data(&PAD_UI_DATA, screen_height);
    const setting_ui_data SETTING_UI_DATA =
        update_setting_ui_data(&DISPLAY_UI_DATA);
    const FilePathList SOUND_FILES = get_sound_files();
    const int SETTING_OFFSET = perform_setting_keys(&SOUND_FILES);

    update_pressed_pad_keys(pressed_pad_keys, PAD_KEYS);
    update_info_data(INFO_DATA, &SOUND_FILES, SETTING_OFFSET);

    // drawing
    BeginDrawing();
    ClearBackground(MPC_BG_COLOR);

    play_pressed_sounds(sounds, pressed_pad_keys);

    draw_pad(&PAD_UI_DATA, pressed_pad_keys);
    draw_display(&DISPLAY_UI_DATA);
    draw_settings(&SETTING_UI_DATA, INFO_DATA);

    EndDrawing();
    UnloadDirectoryFiles(SOUND_FILES); // no memory leaks
  }

  CloseAudioDevice();
  CloseWindow();

  return 0;
}
