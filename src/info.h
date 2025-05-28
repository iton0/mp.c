// Copyright (c) 2025 iton0. All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for full license information.

#ifndef INFO_H_
#define INFO_H_

#include <raylib.h>

const FilePathList get_sound_files(void);

const char **update_info_data(const char **info_data,
                              const FilePathList *files_ptr, const int offset);

#endif
