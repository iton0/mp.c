// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#ifndef DISPLAY_H_
#define DISPLAY_H_
// NOTE: display needs to show both sounds in the directory and sounds used on
// pads
// TODO: need to define a directory name to hold all sounds

#include "pad.h"

typedef struct DisplayUiData {
  ui_frame_data bg;
  ui_frame_data main;
} display_ui_data;

const display_ui_data update_display_ui_data(const pad_ui_data ui_data,
                                             const int screen_height);

void draw_display(const display_ui_data ui_data);

#endif
