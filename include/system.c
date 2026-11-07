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


typedef enum opcode{
	MOVE,
	DRAW,
}opcode;

#include "utils.h"

void put_point(opcode op, float x, float y){

}

