// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "key.h"
#include "pad.h"

int main(void) {
  const int SCREEN_WIDTH = 1250, SCREEN_HEIGHT = 950, FPS = 30;
  const uint8_t *PAD_KEYS = get_pad_keys();
  bool *pressed_keys = get_pressed_keys();

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mp.c");
  SetTargetFPS(FPS);

  init_pad();

  while (!WindowShouldClose()) {
    // update variables here
    update_pressed_keys(pressed_keys, PAD_KEYS);

    // drawing
    BeginDrawing();
    ClearBackground(RAYWHITE);

    draw_pad(pressed_keys);

    EndDrawing();
  }

  deinit_pad();

  CloseWindow();

  return 0;
}
