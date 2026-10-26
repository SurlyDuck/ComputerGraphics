#include "utils.h"

void write_ppm(uint32_t *buffer, const char *path, size_t buffer_width, size_t buffer_height){
	FILE *file = fopen(path, "w+");
	assert(file);
	const char header[] = "P3\n320 200\n255\n";

	fwrite(header, sizeof header[0], sizeof header-1, file);
	for(size_t y = 0; y < buffer_height; ++y){
		for(size_t x = 0; x < buffer_width; ++x){
			uint32_t color = buffer[buffer_width * y + x];
			uint8_t red    = color >> 24;
			uint8_t green  = color >> 16 & 0xFF;
			uint8_t blue   = color >> 8 & 0xFF;

			fprintf(file, "%d%4d%4d\n", red, green, blue);

		}
	}

	fclose(file);
	
}
