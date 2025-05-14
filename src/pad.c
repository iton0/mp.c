// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "pad.h"
#include "util.h"

// pad may have:
// - sound
// TODO: how to properly implement this embedded in struct or dynamic/heap
// NOTE: Sounds have relatively big memory footprint and would be 16 of them
void init_pad(void) {}

void deinit_pad(void) {}

void draw_pad(const bool *pressed_keys) {
  static const Color PAD_BG_COLOR = LIGHTGRAY, BUTTON_COLOR = GRAY,
                     OUTLINE_COLOR = DARKGRAY;
  static const int BUTTON_WIDTH = 100, BUTTON_HEIGHT = 100, BUTTON_PADDING = 15;
  static const int PAD_BG_SIZE = BUTTON_WIDTH * GRID_ROWS + BUTTON_PADDING * 5;
  static const float OUTLINE_THICKNESS = 5.f;
  const int SCREEN_WIDTH = GetScreenWidth(), SCREEN_HEIGHT = GetScreenHeight();
  const float PAD_BG_X = SCREEN_WIDTH / 10.f,
              PAD_BG_Y = SCREEN_HEIGHT - (PAD_BG_SIZE + BUTTON_PADDING);
  const Vector2 PAD_BG_POS = {PAD_BG_X, PAD_BG_Y};

  // draw pad background
  DrawRectangleV(PAD_BG_POS, (Vector2){PAD_BG_SIZE, PAD_BG_SIZE}, PAD_BG_COLOR);

  // draw buttons
  for (uint8_t row_idx = 0; row_idx < GRID_ROWS; ++row_idx) {
    for (uint8_t col_idx = 0; col_idx < GRID_COLS; ++col_idx) {
      const int BUTTON_IDX = row_idx * GRID_COLS + col_idx;
      const float BUTTON_X = PAD_BG_POS.x + BUTTON_PADDING +
                             (col_idx * (BUTTON_WIDTH + BUTTON_PADDING)),
                  BUTTON_Y = PAD_BG_POS.y + BUTTON_PADDING +
                             (row_idx * (BUTTON_WIDTH + BUTTON_PADDING));
      const Vector2 BUTTON_POS = (Vector2){BUTTON_X, BUTTON_Y},
                    BUTTON_SIZE = (Vector2){BUTTON_WIDTH, BUTTON_HEIGHT};

      DrawRectangleV(BUTTON_POS, BUTTON_SIZE, BUTTON_COLOR);
      if (pressed_keys[BUTTON_IDX]) {
        const Rectangle OUTLINE =
            (Rectangle){BUTTON_X, BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT};
        DrawRectangleLinesEx(OUTLINE, OUTLINE_THICKNESS, OUTLINE_COLOR);
      }
    }
  }
}
