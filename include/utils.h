// Subroutines used for lots of examples

#ifndef UTILS_H_
#define UTILS_H_

#include <stdint.h>
#include <stdio.h>
#include <assert.h>

void write_ppm(uint32_t *buffer, const char *path, size_t buffer_width, size_t buffer_height);

#endif // UTILS_H_
