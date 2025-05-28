// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "pad.h"

typedef struct DisplayUiData {
  ui_frame_data bg;
  ui_frame_data main;
  int main_outline_thickness;
} display_ui_data;

const display_ui_data update_display_ui_data(const pad_ui_data *ui_data_ptr,
                                             const int screen_height);

void draw_display(const display_ui_data *ui_data_ptr);

#endif
