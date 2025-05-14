// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "pad.h"
#include "util.h"

#include <raylib.h>
#include <stdint.h>

void draw_pad(const bool *pressed_keys) {
  static const Color PAD_BG_COLOR = LIGHTGRAY;
  static const Color BUTTON_COLOR = GRAY;
  static const Color OUTLINE_COLOR = DARKGRAY;
  const int SCREEN_WIDTH = GetScreenWidth();
  const int SCREEN_HEIGHT = GetScreenHeight();
  const int BUTTON_WIDTH = SCREEN_HEIGHT / 8;
  const int BUTTON_HEIGHT = BUTTON_WIDTH;
  const int BUTTON_PADDING = BUTTON_WIDTH / 8;
  const int PAD_BG_PADDING = BUTTON_PADDING * 3;
  const int PAD_BG_SIZE =
      BUTTON_WIDTH * GRID_ROWS + BUTTON_PADDING * 3 + PAD_BG_PADDING * 2;
  const float OUTLINE_THICKNESS = BUTTON_WIDTH / 20.f;
  const float PAD_BG_X = SCREEN_WIDTH / 10.f;
  const float PAD_BG_Y = SCREEN_HEIGHT - (PAD_BG_SIZE + BUTTON_PADDING * 2);
  const Vector2 PAD_BG_SIZE_V = {PAD_BG_SIZE, PAD_BG_SIZE};
  const Vector2 PAD_BG_POS = {PAD_BG_X, PAD_BG_Y};

  // draw pad background
  DrawRectangleV(PAD_BG_POS, PAD_BG_SIZE_V, PAD_BG_COLOR);

  // draw buttons
  for (uint8_t row_idx = 0; row_idx < GRID_ROWS; ++row_idx) {
    for (uint8_t col_idx = 0; col_idx < GRID_COLS; ++col_idx) {
      const int BUTTON_IDX = row_idx * GRID_COLS + col_idx;
      const float BUTTON_X = PAD_BG_X + PAD_BG_PADDING +
                             (col_idx * (BUTTON_WIDTH + BUTTON_PADDING));
      const float BUTTON_Y = PAD_BG_Y + PAD_BG_PADDING +
                             (row_idx * (BUTTON_WIDTH + BUTTON_PADDING));
      const Vector2 BUTTON_POS = (Vector2){BUTTON_X, BUTTON_Y};
      const Vector2 BUTTON_SIZE = (Vector2){BUTTON_WIDTH, BUTTON_HEIGHT};

      DrawRectangleV(BUTTON_POS, BUTTON_SIZE, BUTTON_COLOR);
      if (pressed_keys[BUTTON_IDX]) { // outline pressed button
        const Rectangle OUTLINE =
            (Rectangle){BUTTON_X, BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT};
        DrawRectangleLinesEx(OUTLINE, OUTLINE_THICKNESS, OUTLINE_COLOR);
      }
    }
  }
}
