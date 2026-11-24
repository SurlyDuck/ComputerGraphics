// Primitives - Exercises
// 2-1 a,b,c --> ../include/core.c

#include "../include/core.h"

// 2-2
void draw_house(){

}

int main(){
	initialize_2();
	set_charup(0.0f, 1.0f);
	set_charspace(0.00f);
	text("Ello");

	move_abs_2(.5, .5);
	line_abs_2(.6, .6);
	make_picture_current();

	while(DISPLAY_is_enabled()){
		// new_frame(); // optional
		DISPLAY_show();
	}
	
	return 0;
}
