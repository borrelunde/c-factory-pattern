#pragma once

enum filesystem_type {
    FILESYSTEM_TYPE_FAT32,
    FILESYSTEM_TYPE_NTFS,
};

struct filesystem_api;

// A generic handle.
typedef const struct filesystem_api** filesystem_t;

struct filesystem_api {
    // Virtual functions regarding dynamic memory allocation.
    void (*free)(filesystem_t filesystem);

    // Virtual functions acting on the filesystem.
    void (*open_file)(filesystem_t filesystem);
    void (*close_file)(filesystem_t filesystem);
};

struct filesystem {
    const struct filesystem_api* api;
};

filesystem_t filesystem_create(enum filesystem_type type);
void filesystem_free(filesystem_t filesystem);
void filesystem_open_file(filesystem_t filesystem);
void filesystem_close_file(filesystem_t filesystem);