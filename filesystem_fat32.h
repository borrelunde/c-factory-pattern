#pragma once

#include "filesystem.h"

struct filesystem_fat32 {
    struct filesystem super;
};

struct filesystem_fat32 *filesystem_fat32_create();
int filesystem_fat32_init(struct filesystem_fat32 *self);