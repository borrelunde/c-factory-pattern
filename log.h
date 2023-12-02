#pragma once

#include <stdio.h>
#include <time.h>

#define LOG(...)                                                            \
    do {                                                                    \
        time_t t = time(NULL);                                              \
        struct tm *tm_info = localtime(&t);                                 \
        char time_str[20];                                                  \
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info); \
        printf("[%s %s]: " __VA_ARGS__ "\n", time_str, __func__);           \
    } while (0)
