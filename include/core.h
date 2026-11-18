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

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>


// Display file opcodes
enum {
	STYLE2 = -3,
	STYLE1 = -2,
	STYLE0 = -1,
	MOVE   = 0,
	LINE   = 2
};

// CORE user routines
void initialize_2();


// Display device subroutines
// In our system the user does not interact with it directly
void DISPLAY_init(void);
