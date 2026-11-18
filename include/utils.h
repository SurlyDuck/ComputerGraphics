// Custom subroutines not present in the book

#ifndef UTILS_H_
#define UTILS_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

void write_ppm(uint32_t *buffer, const char *path, size_t buffer_width, size_t buffer_height);

#endif // UTILS_H_
