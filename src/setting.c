// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "setting.h"

#include <stdint.h>

const setting_ui_data update_setting_ui_data(const display_ui_data ui_data) {
  const Vector2 POS = ui_data.main.position;
  const int FONT_SIZE = ui_data.main.size.y / TEXT_ROWS;

  return (setting_ui_data){
      .position = POS,
      .font_size = FONT_SIZE,
  };
}

// TODO: needs to take both ui data and regular information data
void draw_settings(const setting_ui_data ui_data) {
  const Vector2 POS = ui_data.position;
  const int FONT_SIZE = ui_data.font_size;

  // TODO: needs to make data displaying dynamic and limit text length to
  // display size
  for (uint8_t i = 0; i < TEXT_ROWS; ++i) {
    DrawText("HELLO", POS.x, POS.y + (FONT_SIZE * i), FONT_SIZE, RAYWHITE);
  }
}
