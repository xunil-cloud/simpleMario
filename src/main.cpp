#include "game.h"
#include <iostream>

int main() {

	int level1[] = {
                  3, 3,-1,-1, -1, -1, 3, 3, 3, 3, -1, 3, 3, -1, -1, -1, -1, -1, 3, 3, 3, -1, -1, -1, 3, 3, -1, -1, 3, 3, -1, -1, -1, -1, -1, -1, -1, -1, 3, 3, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, 3, -1,  -1, -1,  -1,  -1, -1,  -1, -1, -1, 3, 3,-1,-1, -1, -1, 3, 3, 3, 3, -1, 3, 3, -1, -1, -1, -1, -1, 3, 3, 3, -1, -1, -1, 3, 3, -1, -1, 3, 3, -1, -1, -1, -1, -1, -1, -1, -1, 3, 3, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, 3, -1,  -1, -1,  -1,  -1, -1,  -1, -1, 3,3,3,3,3,

				  3, 3,-1, 3, -1, -1, 3, 3, 3, 3, -1, 3, 3, -1,  3,  3, -1, -1, 3, 3, 3, -1, -1,  3, 3, 3, -1, -1, 3, 3, -1,  3, -1,  3,  3,  3, -1, -1, 3, 3, -1, -1, -1,  3, 3,  3, -1, -1, -1, -1, 3,  3,   3,  3,   3,  -1, -1,  -1,  3,  3,  3, 3,-1, 3, -1, -1, 3, 3, 3, 3, -1, 3, 3, -1,  3,  3, -1, -1, 3, 3, 3, -1, -1,  3, 3, 3, -1, -1, 3, 3, -1,  3, -1,  3,  3,  3, -1, -1, 3, 3, -1, -1, -1,  3, 3,  3, -1, -1, -1, -1, 3,  3,   3,  3,   3,  -1, -1,  -1,  3,  3,3,3,3,3,

				  3, 3, 3, 3, -1, -1, 3, 3, 3, 3, -1, 3, 3,  3,  3,  3, -1, -1, 3, 3, 3, -1, -1,  3, 3, 3, -1, -1, 3, 3, -1,  3, -1,  3,  3,  3, -1, -1, 3, 3, -1, -1,  3,  3, 3,  3,  3,  3,  3,  3, 3,  3,   3,  3,   3,  -1, -1,  -1,  3,  3, 3, 3, 3, 3, -1, -1, 3, 3, 3, 3, -1, 3, 3,  3,  3,  3, -1, -1, 3, 3, 3, -1, -1,  3, 3, 3, -1, -1, 3, 3, -1,  3, -1,  3,  3,  3, -1, -1, 3, 3, -1, -1,  3,  3, 3,  3,  3,  3,  3,  3, 3,  3,   3,  3,   3,  -1, -1,  -1,  3,  3,3,3,3,3, };

	

	int level2[] = {
	                 -1, -1, -1, 16, 16, -1, 16, 16, -1, 16, 16, -1, -1, -1, -1, -1, 16, 16, -1, -1, -1, 16, 16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 16, 16, -1, 16, 16, -1, 16, 16, -1, -1, -1, -1, -1, 16, 16, -1, -1, -1, 16, 16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 16, 16, -1, 16, 16, -1, 16, 16, -1, -1, -1, -1, -1, 16, 16, -1, -1, -1, 16, 16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 16, 16, -1, 16, 16, -1, 16, 16, -1, -1, -1, -1, -1, 16, 16, -1, -1, -1, 16, 16, -1, -1, -1, -1, -1, -1, 16,16,16,16,16,

					 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, 16, 16, 16, 16, -1, -1, -1, -1, 16, 16, -1, 16, -1, -1, 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, 16, 16, 16, 16, -1, -1, -1, -1, 16, 16, -1, 16, -1, -1, 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, 16, 16, 16, 16, -1, -1, -1, -1, 16, 16, -1, 16, -1, -1, 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, 16, 16, 16, 16, -1, -1, -1, -1, 16, 16, -1, 16, -1, 16,16,16,16,16,

					 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, 16, 16, 16, 16, -1, -1, -1, -1, 16, 16, -1, 16, -1, 16, 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, 16, 16, 16, 16, -1, -1, -1, -1, 16, 16, -1, 16, -1, 16, 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, 16, 16, 16, 16, -1, -1, -1, -1, 16, 16, -1, 16, -1, 16, 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, -1, -1, 16, 16, -1, -1, 16, 16, 16, 16, -1, -1, -1, -1, 16, 16, -1, 16, -1, 16,16,16,16,16, };






	int level3[] = { -1, -1, -1, -1, 29, 29, -1, -1, -1, -1, 29, 29, -1, -1, 29, 29, -1, -1, -1, -1, -1, -1, 29, 29, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, 29, 29, -1, -1, -1, -1, 29, 29, -1, -1, 29, 29, -1, -1, -1, -1, -1, -1, 29, 29, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, 29, 29, -1, -1, -1, -1, 29, 29, -1, -1, 29, 29, -1, -1, -1, -1, -1, -1, 29, 29, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, 29, 29, -1, -1, -1, -1, 29, 29, -1, -1, 29, 29, -1, -1, -1, -1, -1, -1, 29, 29, -1, 29, -1, -1, -1, 29,29,29,29,29,

				     -1, -1, -1, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, 29, 29, -1, -1, -1, -1, -1, -1, -1 ,-1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, 29, 29, -1, -1, -1, -1, -1, -1, -1 ,-1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, 29, 29, -1, -1, -1, -1, -1, -1, -1 ,-1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, 29, 29, -1, -1, -1, -1, -1, -1, -1 ,-1, -1, -1, -1, 29, -1,29,29,29,29,29,

					 29, 29, -1, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, 29, 29, -1, -1, -1, 29, -1, -1, -1, -1, 29, -1, 29, -1, -1, 29, 29, 29, -1, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, 29, 29, -1, -1, -1, 29, -1, -1, -1, -1, 29, -1, 29, -1, -1, 29, 29, 29, -1, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, 29, 29, -1, -1, -1, 29, -1, -1, -1, -1, 29, -1, 29, -1, -1, 29, 29, 29, -1, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, 29, 29, -1, -1, -1, 29, -1, -1, -1, -1, 29, -1, 29, -1, -1, 29,29,29,29,29, };
	

	int* level[] = { level1,level2,level3 };

	    int c1[] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
			-1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,0,};
	    
		
		int c2[] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				 -1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,0, };
		
		
		int c3[] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				 -1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,0,0, };
		
		int* c[] = { c1, c2, c3 };

	Game game(level, c);
	game.init();
	game.start();
	return 0;
}