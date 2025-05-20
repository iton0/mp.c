// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "setting.h"

#include <stdint.h>

const setting_ui_data update_setting_ui_data(const display_ui_data ui_data) {
  static const int OFFSET_X = 3;
  static const int OFFSET_Y = 5;
  const ui_frame_data MAIN = ui_data.main;
  const Vector2 MAIN_POS = MAIN.position;
  const Vector2 POS = {MAIN_POS.x + OFFSET_X, MAIN_POS.y + OFFSET_Y};
  const int FONT_SIZE = (MAIN.size.y - OFFSET_Y) / TEXT_ROWS;

  return (setting_ui_data){
      .position = POS,
      .font_size = FONT_SIZE,
  };
}

// TODO: needs to take both ui data and regular information data
void draw_settings(const setting_ui_data ui_data) {
  static const Color COLOR = {130, 248, 250, 255};
  const Vector2 POS = ui_data.position;
  const int FONT_SIZE = ui_data.font_size;

  // TODO: needs to make data displaying dynamic and limit text length to
  // display size
  for (uint8_t i = 0; i < TEXT_ROWS; ++i) {
    DrawText("HELLO", POS.x, POS.y + (FONT_SIZE * i), FONT_SIZE, COLOR);
  }
}
