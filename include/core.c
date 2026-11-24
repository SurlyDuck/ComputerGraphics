#define MAX_OPCODES 1024*1024

#include "core.h"

typedef struct{
	int16_t opcode;
	float operand_x;
	float operand_y;
}instruction;

typedef struct {
	instruction *instructions;
	size_t count; /* FREE */
	size_t capacity;
}display_file;

static display_file df      = {0};
static int erase_frame      = 0;
static float df_pen_x       = 0.00f;
static float df_pen_y       = 0.00f;
static float chrsp_x        = 0.00f;
static float chrsp_y        = 0.00f;
static float chr_separation = 0.00f;

//---------------------------------------------------------------------
// Subroutines for ENTERING/READING commands into/from the display file
//---------------------------------------------------------------------
// 2.1
void put_point(int16_t opcode, float x, float y){
	assert(df.count < MAX_OPCODES);
	
	if(df.count == 0){
		df.instructions = (instruction*) malloc(sizeof(instruction) * 32);
		df.capacity = sizeof(instruction) * 32;
	}else if(df.capacity < (df.count+1) * sizeof(instruction)){
		df.instructions = (instruction*) realloc(df.instructions, df.capacity + sizeof(instruction) * 32);
		df.capacity += sizeof(instruction) * 32;
	}
	
	instruction new_instruction = {opcode, x, y};
	df.instructions[df.count++] = new_instruction;
}

// 2.2
void get_point(size_t nth, int16_t *op, float *x, float *y){
	*op = df.instructions[nth].opcode;
	*x  = df.instructions[nth].operand_x;
	*y  = df.instructions[nth].operand_y;
}

// 2.3
void display_file_enter(int16_t op){
	put_point(op, df_pen_x, df_pen_y);
}

// 2.4
void move_abs_2(float x, float y){
	df_pen_x = x;
	df_pen_y = y;

	display_file_enter(MOVE);
}

// 2.5
void line_abs_2(float x, float y){
	df_pen_x = x;
	df_pen_y = y;

	display_file_enter(LINE);
}

// 2.6
void move_rel_2(float dx, float dy){
	df_pen_x += dx;
	df_pen_y += dy;

	display_file_enter(MOVE);
}

// 2.7
void line_rel_2(float dx, float dy){
	df_pen_x += dx;
	df_pen_y += dy;

	display_file_enter(LINE);
}

//---------------------------------------------------------------
// Subroutines for EXECUTING commands from the interpreter
//---------------------------------------------------------------
// 2.8
void do_move(float x, float y){
	size_t width  = DISPLAY_get_width();
	size_t height = DISPLAY_get_height();
	
	DISPLAY_set_frame_pen(width * x, height - height * y);
}

// 2.9
void do_line(float x, float y){
	int16_t x1, y1, x2, y2;
	size_t width  = DISPLAY_get_width();
	size_t height = DISPLAY_get_height();

	DISPLAY_get_frame_pen(&x1, &y1);
	DISPLAY_set_frame_pen((int16_t)(x * width), (int16_t)(height - height * y));
	DISPLAY_get_frame_pen(&x2, &y2);

	DISPLAY_dda(x1, y1, x2, y2);
}

// 2.18 
void do_char(){

}

// 2.21
void do_style(int16_t op){

}

//---------------------------------------------------------------
// Subroutines for INTERPRETING commands from the display file
//---------------------------------------------------------------
// 2.10
void interpret(size_t start, size_t count){
	for(size_t i = start; i < count; ++i){
		switch(df.instructions[i].opcode){
			case MOVE: do_move(df.instructions[i].operand_x, df.instructions[i].operand_y); break;
			case LINE: do_line(df.instructions[i].operand_x, df.instructions[i].operand_y); break;
			default: break;
		}
	}
}

// 2.11
void new_frame(){
	erase_frame = 1;
}

// 2.12
void make_picture_current(){
	DISPLAY_start();
	
	if(erase_frame) DISPLAY_erase();
	erase_frame = 0;
	
	if(df.count > 0){
		interpret(0, df.count);
	}
	
	DISPLAY_show();
}

// 2.13 initialization of line drawing
void initialize_2a(){
	DISPLAY_init();
}

// 2.19 Initialization of character drawing
void initialize_2b(){
	initialize_2a();
}

// 2.24
void initialize_2(){
	initialize_2b();
	do_style(-1);
}

// 2.14
void set_charup(float dx, float dy){
	float chrup_normalized_dem = dx*dx + dy*dy;
	assert(chrup_normalized_dem > 0.0001 && "No charup direction");

	uint8_t chr_width, chr_height;
	DISPLAY_get_chr_size(&chr_width, &chr_height);
	
	float default_space = (float)(dy*chr_width) + (float)(dx*chr_height);
	default_space = (default_space + default_space*chr_separation) / chrup_normalized_dem;

	chrsp_x = default_space * dy;
	chrsp_y = default_space * -dx;
}

// 2.15
void set_charspace(float space){
	chr_separation = space;
	set_charup(chrsp_y, -chrsp_x);
}

// 2.16
void text(const char *text){
	size_t length = 0;
	while(text[length++]) length;

	// TODO
}

