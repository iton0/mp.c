// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "setting.h"
#include "color.h"

#include <stdint.h>

const setting_ui_data
update_setting_ui_data(const display_ui_data *ui_data_ptr) {
  const ui_frame_data MAIN = ui_data_ptr->main;
  const Vector2 MAIN_POS = MAIN.position;
  const int OFFSET_X = ui_data_ptr->main_outline_thickness;
  const int OFFSET_Y = OFFSET_X;
  const Vector2 POS = {MAIN_POS.x + OFFSET_X, MAIN_POS.y + OFFSET_Y};
  const int FONT_SIZE = (MAIN.size.y - OFFSET_Y * 2) / DISPLAY_ROWS;

  return (setting_ui_data){
      .position = POS,
      .font_size = FONT_SIZE,
  };
}

void draw_settings(const setting_ui_data *ui_data_ptr, const char **info_data) {
  const Vector2 POS = ui_data_ptr->position;
  const int FONT_SIZE = ui_data_ptr->font_size;

  for (uint8_t i = 0; i < DISPLAY_ROWS; ++i) {
    DrawText(info_data[i], POS.x, POS.y + (FONT_SIZE * i), FONT_SIZE,
             DISPLAY_TEXT_COLOR);
  }
}
