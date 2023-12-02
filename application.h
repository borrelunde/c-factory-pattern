#pragma once

#include "filesystem.h"

struct application {
    filesystem_t filesystem;
};

int application_init(struct application *self);
int application_deinit(struct application *self);

void application_run(struct application *self);