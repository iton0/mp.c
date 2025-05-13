// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#ifndef PAD_H_
#define PAD_H_

#include <raylib.h>
#include <stdint.h>

#define PAD_NUM 16

// TODO: need to make pad struct

void init_pad(void);
void dinit_pad(void);

const uint8_t *get_pad_keys(void);

void update_pad(void);
void draw_pad(void);

#endif
