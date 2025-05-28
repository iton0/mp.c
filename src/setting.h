// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#ifndef SETTING_H_
#define SETTING_H_

#include "display.h"

typedef struct setting_ui_data {
  Vector2 position;
  int font_size;
} setting_ui_data;

const setting_ui_data
update_setting_ui_data(const display_ui_data *ui_data_ptr);
void draw_settings(const setting_ui_data *ui_data_ptr, const char **info_data);

#endif
