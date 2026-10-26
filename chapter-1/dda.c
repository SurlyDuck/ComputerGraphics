// Algorithm for changing pixel values of the frame buffer along a line segment
// Chapter 1
// Pages 12-13

#include <stdint.h>
#include <unistd.h>
#include <stddef.h>
#include "../include/utils.h"

#define BUFFER_WIDTH  320
#define BUFFER_HEIGHT 200

uint32_t frame_buffer[BUFFER_WIDTH * BUFFER_HEIGHT] = {0};

void dda(int x1, int y1, int x2, int y2, uint8_t intensity){
	ssize_t dx = x2 - x1;
	ssize_t dy = y2 - y1;
	size_t steps = (dx > dy) ? dx : dy;
	if (!steps) steps = 1;
	
	float dx_step = (float)(dx) / (float)(steps);
	float dy_step = (float)(dy) / (float)(steps);
	
	float x = x1; 
	float y = y1; 
	for(size_t u = 0; u < steps; ++u){
		// Intensity of the red component (RRGGBBAA = 32 bits color depth)
		frame_buffer[(int)(BUFFER_WIDTH * (int)(y) + x)] = intensity << 24; 

		x += dx_step;
		y += dy_step;
	} 

	frame_buffer[(int)(BUFFER_WIDTH * (int)(y) + x)] = intensity << 24;
}


int main(){
	dda(0, 0, BUFFER_WIDTH-1, BUFFER_HEIGHT-1, 0xFF);
	dda(0, BUFFER_HEIGHT-1, BUFFER_WIDTH-1, 0, 0xFF);

	write_ppm(frame_buffer, "./output.ppm", BUFFER_WIDTH, BUFFER_HEIGHT);

	return 0;
}
