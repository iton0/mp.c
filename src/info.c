// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#include "info.h"
#include "util.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// TODO: make this conditionally run when modifying the sound directory
const char **update_info_data(const char **info_data) {
  static const size_t PATH_LEN =
      strlen("assets") + strlen(PATH_SEPARATOR) + strlen("audio") + 1;
  char dir_path_buf[PATH_LEN];

  snprintf(dir_path_buf, sizeof(dir_path_buf), "%s%s%s", "assets",
           PATH_SEPARATOR, "audio");
  // TODO: find out why below is causing memory leak
  FilePathList files = LoadDirectoryFiles(dir_path_buf);

  for (uint8_t i = 0; i < TEXT_ROWS; ++i) {
    info_data[i] = GetFileName(files.paths[i]);
  }

  return info_data;
}
