// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "pad.h"

#include <stdint.h>

static const uint8_t PAD_KEYS[PAD_NUM] = {
    KEY_Q, KEY_W, KEY_E, KEY_R, // row 1
    KEY_A, KEY_S, KEY_D, KEY_F, // row 2
    KEY_Z, KEY_X, KEY_C, KEY_V, // row 3
    KEY_U, KEY_I, KEY_O, KEY_P, // row 4
};

const uint8_t *get_pad_keys(void) { return PAD_KEYS; }

void init_pad(void) {}

void deinit_pad(void) {}

void draw_pad(void) {}
