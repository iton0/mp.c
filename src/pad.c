// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "pad.h"

static const uint8_t PAD_KEYS[PAD_NUM] = {
    KEY_Q, KEY_W, KEY_E, KEY_R, KEY_A, KEY_S, KEY_D, KEY_F,
    KEY_Z, KEY_X, KEY_C, KEY_V, KEY_U, KEY_I, KEY_O, KEY_P,
};

const uint8_t *get_pad_keys(void) { return PAD_KEYS; }

// pad needs to have:
// - shape
// - position
// - key
// - sound
void init_pad(void) {}

void dinit_pad(void) {}

void draw_pad(void) {
  static const Color PAD_BG_COLOR = LIGHTGRAY, BUTTON_COLOR = GRAY;
  static const int BUTTON_WIDTH = 100, BUTTON_HEIGHT = 100, BUTTON_PADDING = 15;
  static const int PAD_BG_SIZE = BUTTON_WIDTH * 4 + BUTTON_PADDING * 5;
  // TODO: update conditional after making pad struct
  const Color OUTLINE_COLOR = (1 == 0) ? BLACK : BUTTON_COLOR;
  const int SCREEN_WIDTH = GetScreenWidth(), SCREEN_HEIGHT = GetScreenHeight();
  const float PAD_BG_X = SCREEN_WIDTH / 10.f,
              PAD_BG_Y = SCREEN_HEIGHT - (PAD_BG_SIZE + BUTTON_PADDING);
  const Vector2 PAD_BG_POS = {PAD_BG_X, PAD_BG_Y};

  // draw pad background
  DrawRectangleV(PAD_BG_POS, (Vector2){PAD_BG_SIZE, PAD_BG_SIZE}, PAD_BG_COLOR);

  // draw buttons
  for (uint8_t row = 0; row < 4; ++row) {
    for (uint8_t col = 0; col < 4; ++col) {
      const float BUTTON_X = PAD_BG_POS.x + BUTTON_PADDING +
                             (col * (BUTTON_WIDTH + BUTTON_PADDING)),
                  BUTTON_Y = PAD_BG_POS.y + BUTTON_PADDING +
                             (row * (BUTTON_WIDTH + BUTTON_PADDING));
      const Vector2 BUTTON_POS = (Vector2){BUTTON_X, BUTTON_Y},
                    BUTTON_SIZE = (Vector2){BUTTON_WIDTH, BUTTON_HEIGHT};

      DrawRectangleV(BUTTON_POS, BUTTON_SIZE, BUTTON_COLOR);
      DrawRectangleLines(BUTTON_X, BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT,
                         OUTLINE_COLOR);
    }
  }
}
