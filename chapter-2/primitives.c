// Primitives - Exercises
// 2-1 a,b,c --> ../include/core.c

#include "../include/core.h"

// 2-2
void draw_house(){

}

int main(){
	initialize_2();
	
	move_abs_2(.5, .5);
	line_rel_2(.4, .4);

	while(DISPLAY_is_enabled()){
		// new_frame(); // optional
		make_picture_current();
	}
	
	return 0;
}
