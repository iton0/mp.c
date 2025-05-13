// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#ifndef KEY_H_
#define KEY_H_

#include <stdbool.h>
#include <stdint.h>

const uint8_t *get_pad_keys(void);
bool *get_pressed_keys(void);
void update_pressed_keys(bool *pressed_buttons, const uint8_t *pad_keys);

#endif
