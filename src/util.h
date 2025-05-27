// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#ifndef UTIL_H_
#define UTIL_H_

#include <raylib.h>

#define GRID_TOTAL 16
#define GRID_ROWS 4
#define GRID_COLS 4

#ifdef _WIN32
#define PATH_SEPARATOR "\\"
#else
#define PATH_SEPARATOR "/"
#endif

typedef struct UiFrameData {
  Vector2 position;
  Vector2 size;
} ui_frame_data;

const ui_frame_data create_ui_frame_data(const Vector2 position,
                                         const Vector2 size);

#endif
