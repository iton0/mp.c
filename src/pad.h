// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#ifndef PAD_H_
#define PAD_H_

#include "util.h"

#include <stdbool.h>

const ui_frame_data draw_pad(const bool *pressed_keys, const int screen_width,
                             const int screen_height);

#endif
