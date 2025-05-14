// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "key.h"
#include "util.h"

void update_pressed_keys(bool *pressed_keys, const uint8_t *pad_keys) {
  for (uint8_t i = 0; i < GRID_TOTAL; ++i) {
    pressed_keys[i] = (IsKeyDown(pad_keys[i]) || IsKeyPressed(pad_keys[i]));
  }
}
