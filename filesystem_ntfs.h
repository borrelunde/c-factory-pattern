#pragma once

#include "filesystem.h"

struct filesystem_ntfs {
    struct filesystem super;
};

struct filesystem_ntfs *filesystem_ntfs_create();
int filesystem_ntfs_init(struct filesystem_ntfs *self);