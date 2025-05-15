// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#ifndef PAD_H_
#define PAD_H_

#include "util.h"

typedef struct PadUiData {
  ui_frame_data bg;
  Vector2 button_size;
  int bg_padding;
  int button_padding;
  float outline_thickness;
} pad_ui_data;

const pad_ui_data update_pad_ui_data(const int screen_width,
                                     const int screen_height);

void draw_pad(const pad_ui_data ui_data, const bool *pressed_keys);

#endif
