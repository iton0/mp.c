// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "key.h"
#include "util.h"

#include <raylib.h>

static const uint8_t PAD_KEYS[GRID_TOTAL] = {
    KEY_Q, KEY_W, KEY_E, KEY_R, // row 1
    KEY_A, KEY_S, KEY_D, KEY_F, // row 2
    KEY_Z, KEY_X, KEY_C, KEY_V, // row 3
    KEY_U, KEY_I, KEY_O, KEY_P, // row 4
};
static bool pressed_keys[GRID_TOTAL] = {false};

bool *get_pressed_keys(void) { return pressed_keys; }

const uint8_t *get_pad_keys(void) { return PAD_KEYS; }

void update_pressed_keys(bool *pressed_keys, const uint8_t *pad_keys) {
  for (uint8_t i = 0; i < GRID_TOTAL; ++i) {
    pressed_keys[i] = IsKeyDown(pad_keys[i]) || IsKeyPressed(pad_keys[i]);
  }
}
