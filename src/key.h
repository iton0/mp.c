// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#ifndef KEY_H_
#define KEY_H_

#include <raylib.h>
#include <stdbool.h>
#include <stdint.h>

const int perform_setting_keys(const FilePathList *files_ptr);

void update_pressed_pad_keys(bool *pressed_pad_keys, const uint8_t *pad_keys);

#endif
