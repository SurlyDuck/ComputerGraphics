// Implementation of the Graphics System showed in the book.
// Subroutines for drawing points, lines from absolute or relative positions, alphanumeric characters and much more.
// Seems to draw inspiration from an "ACM CORE Graphics System".
//
// Since implementing this system is part of the exercises, the answers for them will be in here.
//
// With this system, the author was aiming at platform independence.
// Back in the day, many display devices did not have a frame buffer and memory was very expensive, thus the use of a display file.
//
// The book presents the system as: Source Program >> Display File >> Interpreter >> Display
// but I think it also can be seem as: Compiller >> Bytecode >> Virtual machine >> Display Device
// 
// The Display File is just a set of instructions like "Draw Line" or "Move pen".

#define MAX_OPCODES 1024*1024

#include "utils.h"

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

static float df_pen_x  = 0.00f;
static float df_pen_y  = 0.00f;
static display_file df = {0};

//---------------------------------------------------------------
// Subroutines for ENTERING commands into the display file
//---------------------------------------------------------------
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

}

// 2.3
void display_file_enter(int16_t op){

}

// 2.4
void move_abs_2(float x, float y){

}

// 2.5
void line_abs_2(float x, float y){

}

// 2.6
void move_rel_2(float dx, float dy){

}

// 2.7
void line_rel_2(float dx, float dy){

}

//---------------------------------------------------------------
// Subroutines for EXECUTING commands from the interpreter
//---------------------------------------------------------------
// 2.8
void do_move(){

}

// 2.9
void do_line(){

}

// 2.18 
void do_char(){

}

//---------------------------------------------------------------
// Subroutines for INTERPRETING commands from the display file
//---------------------------------------------------------------
// 2.10
void interpret(size_t start, size_t count){

}

// 2.11
void new_frame(){

}

// 2.12
void make_picture_current(){

}

// 2.13
void initialize_2a(){

}

// 2.19
void initialize_2b(){

}

// 2.14
void set_charup(){

}

// 2.15
void set_charspace(){

}

// 2.16
void text(const char *text){

}
