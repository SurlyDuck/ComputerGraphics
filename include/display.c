// Display control code.

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

#include "core.h"
#include "raylib.h"

int16_t DISPLAY_frame_pen_x = 0;
int16_t DISPLAY_frame_pen_y = 0;

void DISPLAY_init(){
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Display Device");
	SetTargetFPS(30);
	ClearBackground(BLACK);
}

void DISPLAY_show(){
	EndDrawing();
}

void DISPLAY_erase(){

}

int DISPLAY_is_enabled(){
	return !WindowShouldClose();
}

