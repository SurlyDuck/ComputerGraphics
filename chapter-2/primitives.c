// Primitives - Exercises
// 2-1 a,b,c --> ../include/core.c

#include "../include/core.h"

// 2-2
void draw_house(){

}

int main(){
	initialize_2();
	
	move_abs_2(.5, .5);
	line_abs_2(.6, .6);
	make_picture_current();

	while(DISPLAY_is_enabled()){
		// new_frame(); // optional
		DISPLAY_show();
	}
	
	return 0;
}
