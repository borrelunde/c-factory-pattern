#include "application.h"

#include <memory.h>

#include "log.h"

int application_init(struct application *self) {
    LOG("Application initialising.");

    // Zero the garbage.
    memset(self, 0, sizeof(*self));

    // Create a filesystem using the factory. The factory dynamically
    // allocates the memory on the heap.
    self->filesystem = filesystem_create(FILESYSTEM_TYPE_NTFS);

    LOG("Application initialised.");
    return 0;
}

int application_deinit(struct application *self) {
    LOG("Application deinitialising.");

    // It is important to deallocate the dynamically allocated
    // filesystem from memory.
    filesystem_free(self->filesystem);

    LOG("Application deinitialised.");
    return 0;
}

void application_run(struct application *self) {
    LOG("Application running.");

    // Perform filesystem operations.
    filesystem_open_file(self->filesystem);
    filesystem_close_file(self->filesystem);

    LOG("Application ran.");
}