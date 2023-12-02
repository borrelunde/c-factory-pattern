#include "filesystem_fat32.h"

#include <malloc.h>
#include <memory.h>

#include "container_of.h"
#include "log.h"

static void filesystem_fat32_free(filesystem_t filesystem) {
    struct filesystem_fat32 *self = CONTAINER_OF(filesystem, struct filesystem_fat32, super.api);

    LOG("Freeing filesystem (FAT32).");
    free(self);
    LOG("Freed filesystem (FAT32).");
}

static void filesystem_fat32_open_file(filesystem_t filesystem) {
    struct filesystem_fat32 *self = CONTAINER_OF(filesystem, struct filesystem_fat32, super.api);

    // Pretend to open file.
    LOG("Opening file (FAT32).");
}

static void filesystem_fat32_close_file(filesystem_t filesystem) {
    struct filesystem_fat32 *self = CONTAINER_OF(filesystem, struct filesystem_fat32, super.api);

    // Pretend to close file.
    LOG("Closing file (FAT32).");
}

const struct filesystem_api filesystem_fat32_api = {
    .free = filesystem_fat32_free,
    .open_file = filesystem_fat32_open_file,
    .close_file = filesystem_fat32_close_file,
};

struct filesystem_fat32 *filesystem_fat32_create() {
    return (struct filesystem_fat32 *)
        malloc(sizeof(struct filesystem_fat32));
}

int filesystem_fat32_init(struct filesystem_fat32 *self) {
    memset(self, 0, sizeof(*self));
    self->super.api = &filesystem_fat32_api;
    return 0;
}