// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "pad.h"

int main(void) {
  const int SCREEN_WIDTH = 1250, SCREEN_HEIGHT = 950;
  const int FPS = 30;

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mp.c");
  SetTargetFPS(FPS);

  init_pad();

  while (!WindowShouldClose()) {
    // update variables here

    // drawing
    BeginDrawing();
    ClearBackground(RAYWHITE);

    draw_pad();

    EndDrawing();
  }

  dinit_pad();

  CloseWindow();

  return 0;
}
