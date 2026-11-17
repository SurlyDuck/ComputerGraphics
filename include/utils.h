// Subroutines used in several examples

#ifndef UTILS_H_
#define UTILS_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

// Display file opcodes
enum {
	STYLE2 = -3,
	STYLE1 = -2,
	STYLE0 = -1,
	MOVE   = 0,
	LINE   = 2
};

void write_ppm(uint32_t *buffer, const char *path, size_t buffer_width, size_t buffer_height);

#endif // UTILS_H_
