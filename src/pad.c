// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "pad.h"

#include <stdint.h>

const pad_ui_data update_pad_ui_data(const int screen_width,
                                     const int screen_height) {
  const int BUTTON_WIDTH = screen_height / 10.5;
  const int BUTTON_HEIGHT = BUTTON_WIDTH;
  const int BG_PADDING = BUTTON_WIDTH / 2;
  const int BUTTON_PADDING = BG_PADDING / 3;
  const int BG_SIZE =
      BUTTON_WIDTH * GRID_ROWS + BUTTON_PADDING * 3 + BG_PADDING * 2;
  const float OUTLINE_THIC = BUTTON_WIDTH / 16.f;
  const float BG_X = screen_width / 10.f;
  const float BG_Y = screen_height - (BG_SIZE + BUTTON_PADDING);
  const Vector2 BG_POS = {BG_X, BG_Y};
  const Vector2 BG_SIZE_V = {BG_SIZE, BG_SIZE};
  const Vector2 BUTTON_SIZE = {BUTTON_WIDTH, BUTTON_HEIGHT};
  const ui_frame_data BG_FRAME_DATA = create_ui_frame_data(BG_POS, BG_SIZE_V);

  return (pad_ui_data){.bg = BG_FRAME_DATA,
                       .button_size = BUTTON_SIZE,
                       .bg_padding = BG_PADDING,
                       .button_padding = BUTTON_PADDING,
                       .outline_thickness = OUTLINE_THIC};
}

void draw_pad(const pad_ui_data ui_data, const bool *pressed_keys) {
  static const Color BG_COLOR = LIGHTGRAY;
  static const Color BUTTON_COLOR = GRAY;
  static const Color OUTLINE_COLOR = DARKGRAY;
  const ui_frame_data BG = ui_data.bg;
  const Vector2 BUTTON_SIZE = ui_data.button_size;
  const int BG_PADDING = ui_data.bg_padding;
  const int BUTTON_PADDING = ui_data.button_padding;

  // draw pad background
  DrawRectangleV(BG.position, BG.size, BG_COLOR);

  // draw buttons
  for (uint8_t row_idx = 0; row_idx < GRID_ROWS; ++row_idx) {
    for (uint8_t col_idx = 0; col_idx < GRID_COLS; ++col_idx) {
      const int BUTTON_IDX = row_idx * GRID_COLS + col_idx;
      const float BUTTON_X = BG.position.x + BG_PADDING +
                             (col_idx * (BUTTON_SIZE.x + BUTTON_PADDING));
      const float BUTTON_Y = BG.position.y + BG_PADDING +
                             (row_idx * (BUTTON_SIZE.y + BUTTON_PADDING));

      DrawRectangleV((Vector2){BUTTON_X, BUTTON_Y}, BUTTON_SIZE, BUTTON_COLOR);
      if (pressed_keys[BUTTON_IDX]) { // outline pressed button
        const Rectangle OUTLINE = {BUTTON_X, BUTTON_Y, BUTTON_SIZE.x,
                                   BUTTON_SIZE.y};
        DrawRectangleLinesEx(OUTLINE, ui_data.outline_thickness, OUTLINE_COLOR);
      }
    }
  }
}
