// File: wildfire.c
// Description: tbd
//
// @author Grace Conley
////////////////////////////////////////////////////////////////////////

#define _DEFAULT_SOURCE

#include "display.h"
#include "wildfire.h"

int main() {

	clear();
	set_cur_pos(1,0);
	put(BURNED);
	set_cur_pos(2,0);
	put(EMPTY);
	set_cur_pos(2,1);
	put(TREE);
	set_cur_pos(2,2);
	put(BURNING);
	set_cur_pos(5,0);
}
