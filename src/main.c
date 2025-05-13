// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "pad.h"

int main(void) {
  const int WIDTH = 1000, HEIGHT = 900, FPS = 30;

  InitWindow(WIDTH, HEIGHT, "Mp.c");
  SetTargetFPS(FPS);

  init_pad();

  while (!WindowShouldClose()) {
    // update variables here

    BeginDrawing();
    ClearBackground(RAYWHITE);

    EndDrawing();
  }

  deinit_pad();

  CloseWindow();

  return 0;
}
