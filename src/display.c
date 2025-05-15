// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "display.h"

const display_ui_data update_display_ui_data(const pad_ui_data ui_data,
                                             const int screen_height) {
  const ui_frame_data pad_bg = ui_data.bg;
  const int BG_WIDTH = pad_bg.size.x;
  const int BG_HEIGHT = screen_height / 6.25;
  const float MAIN_OFFSET_X = ui_data.button_size.x / 1.15;
  const float MAIN_OFFSET_Y = ui_data.button_padding * 1.75;
  const int MAIN_WIDTH = BG_WIDTH - MAIN_OFFSET_X * 2;
  const int MAIN_HEIGHT = BG_HEIGHT - MAIN_OFFSET_Y * 2;
  const float BG_X = pad_bg.position.x;
  const float BG_Y = (pad_bg.position.y - BG_HEIGHT) / 2;
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
  static const Color BG_COLOR = {0, 0, 0, 195};       // black with medium alpha
  static const Color MAIN_COLOR = {0, 121, 241, 130}; // blue with low alpha

  // draw display background
  DrawRectangleV(ui_data.bg.position, ui_data.bg.size, BG_COLOR);

  // draw main display
  DrawRectangleV(ui_data.main.position, ui_data.main.size, MAIN_COLOR);

  // TODO: should i put the listing logic here or make it seperate file?
}
