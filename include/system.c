// Implementation of the Graphics System showed in the book.
// Subroutines for drawing points, lines from absolute or relative positions, alphanumeric characters and much more.
// Seems to draw inspiration from a "ACM CORE Graphics System".
//
// Since implementing this system is part from the exercises, the answers for them will be in here.
//
// With this system the author was aiming at platform independence.
// Back in the day, many display devices did not have a frame buffer, thus the use of a display file.
// Nowdays a frame buffer is unavoidable modern hardware, but we will keep the author's vision and historical context in the implementation.
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
	instruction items;
	size_t count; /* FREE */
	size_t capacity;
}instructions;

static float df_pen_x = 0.00f;
static float df_pen_y = 0.00f;

// 2-1
void put_point(opcode op, float x, float y){

}

// 2-2
void get_point(size_t nth, opcode *op, float *x, float *y){

}

// 2-3
void display_file_enter(opcode op){

}

// 2-4
void move_abs_2(float x, float y){

}

// 2-5
void line_abs_2(float x, float y){

}

// 2-6
void move_rel_2(float dx, float dy){

}

// 2-7
void line_rel_2(float dx, float dy){

}
