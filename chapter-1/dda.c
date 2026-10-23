// Algorithm for changing pixel values of the frame buffer along a line segment
// Chapter 1
// Pages 12-13

#include <stdint.h>
#include <unistd.h>
#include <stddef.h>
#include <assert.h>
#include <stdio.h>

#define BUFFER_WIDTH  320
#define BUFFER_HEIGHT 200

uint8_t frame_buffer[BUFFER_WIDTH * BUFFER_HEIGHT] = {0};

void dda(int x1, int y1, int x2, int y2, uint8_t intensity){
	ssize_t dx = x2 - x1;
	ssize_t dy = y2 - y1;
	size_t steps = (dx > dy) ? dx : dy;
	if (!steps) steps = 1;
	
	float dx_step = (float)(dx) / (float)(steps);
	float dy_step = (float)(dy) / (float)(steps);
	
	float x = x1; 
	float y = y1; 
	for(size_t u = 1; u < steps; ++u){
		frame_buffer[(int)(BUFFER_WIDTH * (int)(y) + x)] = intensity;

		x += dx_step;
		y += dy_step;
	} 

	frame_buffer[(int)(BUFFER_WIDTH * (int)(y) + x)] = intensity;
}

// TODO: This will be used in other examples,
// move it to a library
void write_ppm(const char *path){
	FILE *file = fopen(path, "w+");
	assert(file);

	const char header[] = "P3\n320 200\n255\n";
	const char rgb_triplet_filled[] = "255   0   0\n";
	const char rgb_triplet_empty[] = "0   0   0\n";

	fwrite(header, sizeof header[0], sizeof header-1, file);

	for(size_t y = 0; y < BUFFER_HEIGHT; ++y){
		for(size_t x = 0; x < BUFFER_WIDTH; ++x){
			if (frame_buffer[BUFFER_WIDTH * y + x])
				fwrite(rgb_triplet_filled, sizeof rgb_triplet_filled[0], sizeof rgb_triplet_filled -1, file);
			else
				fwrite(rgb_triplet_empty, sizeof rgb_triplet_empty[0], sizeof rgb_triplet_empty -1, file);
		}
	}

	fclose(file);
	
}

int main(){
	dda(0, 0, BUFFER_WIDTH-1, BUFFER_HEIGHT-1, 100);
	dda(0, BUFFER_HEIGHT-1, BUFFER_WIDTH-1, 0, 100);

	write_ppm("./output.ppm");

	return 0;
}
