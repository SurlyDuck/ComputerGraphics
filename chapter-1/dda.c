// Algorithm for changing pixel values of the frame buffer along a line segment
// Chapter 1
// Pages 12-23

#include <stdint.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utils.h"

#define BUFFER_WIDTH  320
#define BUFFER_HEIGHT 200

uint32_t frame_buffer[BUFFER_WIDTH * BUFFER_HEIGHT] = {0};

// Algorithm 1-1
void dda(int x1, int y1, int x2, int y2, uint8_t intensity){
	int32_t dx = x2 - x1;
	int32_t dy = y2 - y1;
	size_t steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
	steps++;
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

void erase(){
	memset(frame_buffer, 0, BUFFER_WIDTH * BUFFER_HEIGHT * sizeof(uint32_t));
}

// Algorithm 1-2
void draw_house(){
	dda(10, 10, 10, 15, 0xFF);
	dda(10, 10, 25, 1, 0xFF);
	dda(40, 10, 25, 1, 0xFF);
	dda(40, 10, 40, 15, 0xFF);
	dda(40, 15, 10, 15, 0xFF);
	write_ppm(frame_buffer, "./house.ppm", BUFFER_WIDTH, BUFFER_HEIGHT);
}

// Algorithm 1-3
#define Y_RANGE 10000.00f
#define X_RANGE 12.00f
#define Y_AXIS_SIZE BUFFER_HEIGHT - 10
#define X_AXIS_SIZE (BUFFER_WIDTH  - 50)
uint16_t year_sales[12] = {2000, 4000, 7000, 6000, 4000, 8000, 8000, 7000, 5000, 6000, 8000, 9000};
void draw_line_graph(){

	// axis
	dda(1, 0, 1, Y_AXIS_SIZE, 0xFF);
	dda(1, Y_AXIS_SIZE, X_AXIS_SIZE, Y_AXIS_SIZE, 0xFF);
	
	for(size_t i = 0; i < sizeof(year_sales)/sizeof(year_sales[0]); ++i){
		float current_x_point = (X_AXIS_SIZE/X_RANGE) * i;
		float current_y_point = Y_AXIS_SIZE - ((float)(year_sales[i]/Y_RANGE) * Y_AXIS_SIZE);
		float last_x_point = current_x_point;
		float last_y_point = current_y_point;

		if(i > 0){
			last_x_point = (X_AXIS_SIZE/X_RANGE) * (i-1);
			last_y_point = Y_AXIS_SIZE - ((float)(year_sales[i-1]/Y_RANGE) * Y_AXIS_SIZE);
		}
		
		dda(last_x_point, last_y_point, current_x_point, current_y_point, 0xFF);
	}

	write_ppm(frame_buffer, "./graph_line.ppm", BUFFER_WIDTH, BUFFER_HEIGHT);
}

void draw_bar_graph(){
	// TODO
}

int main(){
	//dda(0, 0, BUFFER_WIDTH-1, BUFFER_HEIGHT-1, 0xFF);
	//dda(0, BUFFER_HEIGHT-1, BUFFER_WIDTH-1, 0, 0xFF);
	erase();
	draw_house();

	erase();
	draw_line_graph();

	return 0;
}
