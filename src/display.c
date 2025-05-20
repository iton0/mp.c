// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "display.h"

const display_ui_data update_display_ui_data(const pad_ui_data ui_data,
                                             const int screen_height) {
  const ui_frame_data PAD_BG = ui_data.bg;
  const int BG_WIDTH = PAD_BG.size.x;
  const int BG_HEIGHT = screen_height / 6;
  const float MAIN_OFFSET_X = ui_data.button_size.x;
  const float MAIN_OFFSET_Y = ui_data.button_padding * 1.75;
  const int MAIN_WIDTH = BG_WIDTH - MAIN_OFFSET_X * 2;
  const int MAIN_HEIGHT = BG_HEIGHT - MAIN_OFFSET_Y * 2;
  const float BG_X = PAD_BG.position.x;
  const float BG_Y = (PAD_BG.position.y - BG_HEIGHT) / 2;
  const float MAIN_X = BG_X + MAIN_OFFSET_X;
  const float MAIN_Y = BG_Y + MAIN_OFFSET_Y;
  const Vector2 BG_POS = {BG_X, BG_Y};
  const Vector2 BG_SIZE = {BG_WIDTH, BG_HEIGHT};
  const Vector2 MAIN_POS = {MAIN_X, MAIN_Y};
  const Vector2 MAIN_SIZE = {MAIN_WIDTH, MAIN_HEIGHT};
  const ui_frame_data BG_FRAME_DATA = create_ui_frame_data(BG_POS, BG_SIZE);
  const ui_frame_data MAIN_FRAME_DATA =
      create_ui_frame_data(MAIN_POS, MAIN_SIZE);

  return (display_ui_data){
      .bg = BG_FRAME_DATA,
      .main = MAIN_FRAME_DATA,
  };
}

void draw_display(const display_ui_data ui_data) {
  static const Color CUSTOM_BLACK = {16, 25, 31, 255};
  static const Color CUSTOM_BLUE = {0, 60, 255, 255};

  // draw display background
  DrawRectangleV(ui_data.bg.position, ui_data.bg.size, CUSTOM_BLACK);

  // draw main display
  DrawRectangleV(ui_data.main.position, ui_data.main.size, CUSTOM_BLUE);
}
