// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "key.h"
#include "util.h"

const int perform_setting_keys(const FilePathList *files_ptr) {
  static int offset = 0;

  if (IsKeyPressed(KEY_J) || IsKeyPressed(KEY_DOWN)) {
    offset = offset + DISPLAY_ROWS > files_ptr->count - 1
                 ? files_ptr->count - DISPLAY_ROWS
                 : offset + 1;
  }
  if (IsKeyPressed(KEY_K) || IsKeyPressed(KEY_UP)) {
    offset = offset == 0 ? 0 : offset - 1;
  }

  return offset;
}

void update_pressed_pad_keys(bool *pressed_pad_keys, const uint8_t *pad_keys) {
  for (uint8_t i = 0; i < GRID_TOTAL; ++i) {
    pressed_pad_keys[i] = (IsKeyPressed(pad_keys[i]) || IsKeyDown(pad_keys[i]));
  }
}
