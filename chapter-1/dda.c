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

// Used for all graph exercises
#define Y_RANGE 10000.00f
#define X_RANGE 12.00f
#define Y_AXIS_SIZE (BUFFER_HEIGHT - 10)
#define X_AXIS_SIZE (BUFFER_WIDTH  - 50)

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

void draw_axis(){
	dda(1, 0, 1, Y_AXIS_SIZE, 0xFF);
	dda(1, Y_AXIS_SIZE, X_AXIS_SIZE, Y_AXIS_SIZE, 0xFF);
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
}

// Algorithm 1-3
uint16_t year_sales[12] = {2000, 4000, 7000, 6000, 4000, 8000, 8000, 7000, 5000, 6000, 8000, 9000};
void draw_line_graph(){
	draw_axis();
	
	for(size_t i = 0; i < sizeof(year_sales)/sizeof(year_sales[0]); ++i){
		float current_x_point = (X_AXIS_SIZE/X_RANGE) * i;
		float current_y_point = Y_AXIS_SIZE - ((float)(year_sales[i]/Y_RANGE) * Y_AXIS_SIZE);
		float last_x_point = current_x_point;
		float last_y_point = current_y_point;

		if(i > 0){
			last_x_point = (X_AXIS_SIZE/X_RANGE) * (i-1);
			last_y_point = Y_AXIS_SIZE - ((float)(year_sales[i-1]/Y_RANGE) * Y_AXIS_SIZE);
		}
		
		dda(last_x_point+1, last_y_point, current_x_point+1, current_y_point, 0xFF);
	}
}

// 1-4
void draw_bar_graph(){
	draw_axis();

	for(size_t i = 0; i < sizeof(year_sales)/sizeof(year_sales[0]); ++i){
		float x = (X_AXIS_SIZE/X_RANGE) * i;
		float y = Y_AXIS_SIZE - ((float)(year_sales[i]/Y_RANGE) * Y_AXIS_SIZE);

		dda(x+1, Y_AXIS_SIZE, x+1, y, 0xFF);
	}
}

// 1-5
void draw_centered_square(uint8_t length){
	size_t origin_x = BUFFER_WIDTH/2 - length/2;
	size_t origin_y = BUFFER_HEIGHT/2 - length/2;
	dda(origin_x, origin_y, origin_x, origin_y + length, 0xFF);
	dda(origin_x + length, origin_y, origin_x + length, origin_y + length, 0xFF);
	dda(origin_x, origin_y, origin_x + length, origin_y, 0xFF);
	dda(origin_x, origin_y + length, origin_x + length, origin_y + length, 0xFF);
}

// 1-6
void draw_curve(){
	// x = y²/10
	draw_axis();
	for(size_t i = 0; i < Y_RANGE; ++i){	
		float y = i;
		float x = (float)(y*y)/10.0f;
		float previous_x = x;
		float previous_y = y;

		if(y > 0){
			previous_y = i - 1;
			previous_x = (float)(previous_y*previous_y)/10.0f;
		}

		//map
		y = (float)((Y_AXIS_SIZE / (Y_RANGE / 1000.0f)) * y);
		x = (float)((X_AXIS_SIZE / X_RANGE) * x);
		previous_y = (float)((Y_AXIS_SIZE / (Y_RANGE / 1000.0f)) * previous_y);
		previous_x = (float)((X_AXIS_SIZE / X_RANGE) * previous_x);

		if(y > Y_AXIS_SIZE-1 || x > X_AXIS_SIZE-1) break;
		
		dda(previous_x+1, Y_AXIS_SIZE - previous_y+1, x+1, Y_AXIS_SIZE - y+1, 0xFF);
	}
}

int main(){
	erase();
	draw_house();
	write_ppm(frame_buffer, "./house.ppm", BUFFER_WIDTH, BUFFER_HEIGHT);

	erase();
	draw_line_graph();
	write_ppm(frame_buffer, "./graph_line.ppm", BUFFER_WIDTH, BUFFER_HEIGHT);

	erase();
	draw_bar_graph();
	write_ppm(frame_buffer, "./graph_bar.ppm", BUFFER_WIDTH, BUFFER_HEIGHT);

	erase();
	draw_centered_square(4);
	draw_centered_square(16);
	draw_centered_square(32);
	draw_centered_square(64);
	write_ppm(frame_buffer, "./squares.ppm", BUFFER_WIDTH, BUFFER_HEIGHT);

	erase();
	draw_curve();
	write_ppm(frame_buffer, "./curve.ppm", BUFFER_WIDTH, BUFFER_HEIGHT);

	return 0;
}
