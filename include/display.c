// Display control code.

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600
#define FONT_SIZE     12

#include "core.h"
#include "../include/raylib.h"

static int16_t frame_pen_x = 0;
static int16_t frame_pen_y = 0;

void DISPLAY_init(){
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Display Device");
	SetTargetFPS(30);
	ClearBackground(BLACK);
}

void DISPLAY_show(){
	EndDrawing();
}

void DISPLAY_start(){
	BeginDrawing();
}

void DISPLAY_erase(){
	ClearBackground(BLACK);
}

int DISPLAY_is_enabled(){
	return !WindowShouldClose();
}

size_t DISPLAY_get_width(void){
	return WINDOW_WIDTH;
}

size_t DISPLAY_get_height(void){
	return WINDOW_HEIGHT;
}

void DISPLAY_dda(int16_t x1, int16_t y1, int16_t x2, int16_t y2){
	DrawLine(x1, y1, x2, y2, GREEN);
}

void DISPLAY_set_frame_pen(int16_t x, int16_t y){
	frame_pen_x = x;
	frame_pen_y = y;
}

void DISPLAY_get_frame_pen(int16_t *x, int16_t *y){
	*x = frame_pen_x;
	*y = frame_pen_y;
}

void   DISPLAY_get_chr_size(uint8_t *chr_width, uint8_t *chr_height){
	*chr_width  = FONT_SIZE/2;
	*chr_height = FONT_SIZE/2;
}

