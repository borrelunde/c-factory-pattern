#include "filesystem.h"

#include "filesystem_fat32.h"
#include "filesystem_ntfs.h"
#include "log.h"

filesystem_t filesystem_create(enum filesystem_type type) {
    switch (type) {
        case FILESYSTEM_TYPE_FAT32: {
            struct filesystem_fat32 *filesystem = filesystem_fat32_create();
            filesystem_fat32_init(filesystem);
            return &filesystem->super.api;
        } break;
        case FILESYSTEM_TYPE_NTFS: {
            struct filesystem_ntfs *filesystem = filesystem_ntfs_create();
            filesystem_ntfs_init(filesystem);
            return &filesystem->super.api;
        } break;
    }
    // In a real application, consider a better alternative than
    // to return NULL when the filesystem type does not exist.
    // For example an error.
    return NULL;
}

void filesystem_free(filesystem_t filesystem) {
    if (filesystem == NULL) {
        LOG("Cannot free. Filesystem is null.");
        return;
    }
    (*filesystem)->free(filesystem);
}

void filesystem_open_file(filesystem_t filesystem) {
    if (filesystem == NULL) {
        LOG("Cannot open file. Filesystem is null.");
        return;
    }
    (*filesystem)->open_file(filesystem);
}

void filesystem_close_file(filesystem_t filesystem) {
    if (filesystem == NULL) {
        LOG("Cannot close file. Filesystem is null.");
        return;
    }
    (*filesystem)->close_file(filesystem);
}