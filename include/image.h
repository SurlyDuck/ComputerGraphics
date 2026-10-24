// Subroutines for rendering images in all examples

#ifndef IMAGE_H_
#define IMAGE_H_

#include <stdint.h>
#include <stdio.h>
#include <assert.h>

void write_ppm(uint32_t *buffer, const char *path, size_t buffer_width, size_t buffer_height);

#endif // IMAGE_H_
