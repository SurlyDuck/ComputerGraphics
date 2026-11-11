// Implementation of the Graphics System showed in the book.
// Subroutines for drawing points, lines from absolute or relative positions, alphanumeric characters and much more.
// Seems to draw inspiration from a "ACM CORE Graphics System".
//
// Since implementing this system is part from the exercises, the answers for them will be in here.
//
// With this system the author was aiming at platform independence.
// Back in the day, many display devices did not have a frame buffer and memory was very expensive, thus the use of a display file.
//
// The book presents the system as: Source Program >> Display File >> Interpreter >> Display
// but I think it also can be seem as: Compiller >> Bytecode >> Virtual machine >> Display Device
// 
// The Display File is just a set of instructions like "Draw Line" or "Move pen".
//
// I took some liberties in using modern features from C  like enums and structures for this this implementation.

#include "utils.h"

typedef enum opcode{
	MOVE = 1,
	LINE = 2
}opcode;

typedef struct{
	opcode op;
	float operand_x;
	float operand_y;
}instruction;

typedef struct {
	instruction *instructions;
	size_t count; /* FREE */
	size_t capacity;
}display_file;

static float df_pen_x = 0.00f;
static float df_pen_y = 0.00f;

//---------------------------------------------------------------
// Subroutines for ENTERING commands into the display file
//---------------------------------------------------------------
// 2.1
void put_point(opcode op, float x, float y){

}

// 2.2
void get_point(size_t nth, opcode *op, float *x, float *y){

}

// 2.3
void display_file_enter(opcode op){

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
