#include "filesystem_ntfs.h"

#include <malloc.h>
#include <memory.h>

#include "container_of.h"
#include "log.h"

static void filesystem_ntfs_free(filesystem_t filesystem) {
    struct filesystem_ntfs *self = CONTAINER_OF(filesystem, struct filesystem_ntfs, super.api);

    LOG("Freeing filesystem (NTFS).");
    free(self);
    LOG("Freed filesystem (NTFS).");
}

static void filesystem_ntfs_open_file(filesystem_t filesystem) {
    struct filesystem_ntfs *self = CONTAINER_OF(filesystem, struct filesystem_ntfs, super.api);

    // Pretend to open file.
    LOG("Opening file (NTFS).");
}

static void filesystem_ntfs_close_file(filesystem_t filesystem) {
    struct filesystem_ntfs *self = CONTAINER_OF(filesystem, struct filesystem_ntfs, super.api);

    // Pretend to close file.
    LOG("Closing file (NTFS).");
}

const struct filesystem_api filesystem_ntfs_api = {
    .free = filesystem_ntfs_free,
    .open_file = filesystem_ntfs_open_file,
    .close_file = filesystem_ntfs_close_file,
};

struct filesystem_ntfs *filesystem_ntfs_create() {
    return (struct filesystem_ntfs *)
        malloc(sizeof(struct filesystem_ntfs));
}

int filesystem_ntfs_init(struct filesystem_ntfs *self) {
    memset(self, 0, sizeof(*self));
    self->super.api = &filesystem_ntfs_api;
    return 0;
}