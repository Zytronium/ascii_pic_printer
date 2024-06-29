#include <stdio.h>
#include "main.h"

int main(void)
{
	int face[16][17] = {
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2 },
			{ 1, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 1, 2 },
			{ 1, 0, 1, 0, 4, 0, 1, 0, 0, 1, 0, 4, 0, 1, 0, 1, 2 },
			{ 1, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 1, 2 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2 },
			{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 2 },
			{ 1, 0, 1, 4, 1, 0, 0, 0, 0, 0, 0, 1, 4, 1, 0, 1, 2 },
			{ 1, 0, 1, 4, 2, 1, 0, 0, 0, 0, 0, 1, 4, 1, 0, 1, 2 },
			{ 1, 0, 0, 4, 4, 2, 1, 0, 0, 0, 0, 1, 4, 1, 0, 1, 2 },
			{ 1, 0, 0, 1, 3, 4, 2, 1, 0, 0, 1, 2, 4, 1, 0, 1, 2 },
			{ 1, 0, 0, 0, 1, 4, 4, 3, 1, 1, 2, 4, 1, 0, 1, 1, 2 },
			{ 1, 0, 0, 0, 0, 1, 2, 4, 4, 4, 4, 1, 0, 2, 1, 1, 2 },
			{ 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 3, 3, 2, 2, 1, -1 },
			{ 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 3, 3, 2, 2, 1, 0, 0 }
	};
	int gradient[10][10] = {
			{ 0, 0, 1, 1, 2, 2, 3, 3, 2, 1 },
			{ 0, 1, 1, 2, 2, 3, 3, 4, 3, 2 },
			{ 1, 1, 2, 2, 3, 3, 4, 4, 4, 3 },
			{ 1, 2, 2, 3, 3, 4, 4, 4, 4, 4 },
			{ 2, 2, 3, 3, 4, 4, 4, 4, 4, 4 },
			{ 2, 3, 3, 4, 4, 4, 4, 4, 4, 4 },
			{ 3, 3, 4, 4, 4, 4, 4, 4, 4, 3 },
			{ 3, 4, 4, 4, 4, 4, 4, 4, 3, 2 },
			{ 4, 4, 4, 4, 4, 4, 4, 3, 2, 1 },
			{ 4, 4, 4, 4, 4, 4, 3, 2, 1, 0 }
	};

	int thinkingBleach[30][42] = {
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 3, 4, 4, 4, 4, 4, 4, 3, 3, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 4, 3, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 3, 4, 3, 3, 3, 3, 3, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 4, 4, 4, 3, 3, 3, 4, 4, 4, 4, 4, 3, 3, 4, 3, 3, 4, 4, 3, 4, 4, 4, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 4, 4, 4, 4, 3, 3, 4, 4, 4, 4, 4, 4, 4, 3, 3, 4, 3, 3, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0 },
			{ 4, 4, 4, 4, 4, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0 },
			{ 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0 },
			{ 4, 4, 4, 4, 4, 4, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0 },
			{ 4, 4, 4, 4, 4, 4, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0 },
			{ 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0 },
			{ 4, 4, 4, 4, 4, 4, 4, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
			{ 4, 4, 4, 4, 4, 4, 4, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 4, 4, 4, 3, 2, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3 },
			{ 3, 3, 3, 4, 4, 4, 3, 3, 3, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3 },
			{ 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3 },
			{ 4, 4, 4, 4, 4, 3, 3, 3, 3, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 3, 3, 3 },
			{ 3, 4, 4, 4, 3, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 3, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
			{ 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 3, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 3, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 2, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 3, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 3, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};

	int stratos[25][34] = {
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -1 },
			{ 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -1 },
			{ 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -1 },
			{ 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -1 },
			{ 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -1 },
			{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -1 },
			{ 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, -1 },
			{ 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, -1 },
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, -1 },
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, -1 },
			{ 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, -1 },
			{ 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, -1 },
			{ 1, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, -1 },
			{ 1, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2 -1 },
			{ 0, 1, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 1, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, -1 },
			{ 0, 1, 2, 2, 2, 2, 3, 2, 1, 1, 2, 2, 2, 2, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
			{ 0, 0, 0, 2, 2, 2, 3, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
			{ 0, 0, 0, 0, 2, 2, 2, 2, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, -1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, -1 }
	};

	int creeper[8][8] = {
			{ 4, 2, 2, 4, 3, 4, 3, 1 },
			{ 1, 2, 2, 2, 1, 3, 2, 3 },
			{ 2, 0, 0, 3, 1, 0, 0, 4 },
			{ 2, 0, 0, 2, 2, 0, 0, 3 },
			{ 3, 2, 3, 0, 0, 4, 1, 2 },
			{ 4, 1, 0, 0, 0, 0, 2, 4 },
			{ 4, 1, 0, 0, 0, 0, 2, 1 },
			{ 2, 3, 0, 3, 4, 0, 1, 2 }
	};

	print_grid_as_pic(10, 10, gradient);
	printf("\n\n\n");
	print_grid_as_pic(16, 17, face);
	printf("\n\n\n");
	rev_grid(16, 17, face);
	print_grid_as_pic(16, 17, face);
	printf("\n\n\n");
	print_grid_as_pic(8, 8, creeper);
	printf("\tAaaw man! ;)\n\n\n");
	print_grid_as_pic(30, 42, thinkingBleach);
	printf("\n\n\n");
	print_grid_as_pic(25, 34, stratos);
	return (0);
}

/**
 * prints a grid of integers as a grid of ascii squares, with shades
 * that correspond to the integers' values, where 4 is fully opaque,
 * 0 is fully transparent, and -1 ends the line.
 *
 * @param grid a 2D array of integers. Rows may be of variable lengths
 * as long as the last integer in the row is -1, otherwise, the remaining
 * numbers must be 0 to represent the end of that row. Anything larger than
 * 4 is skipped, and anything smaller than 0 ends the entire row.
 * @return nothing
 */
void print_grid_as_pic(int rows, int cols, int grid[rows][cols])
{
	int x = 0, y = 0;

	while (grid[y][0] >= 0 && y < rows)
	{
		while (grid[y][x] >= 0 && x < cols)
		{
			char pixel;

			switch (grid[y][x])
			{
				case 0:
					pixel = ' ';
					break;

				case 1:
					pixel = 176;
					break;

				case 2:
					pixel = 177;
					break;

				case 3:
					pixel = 178;
					break;

				case 4:
					pixel = 219;
					break;

				default:
					pixel = '\0';
					break;
			}
			printf("%c%c ", pixel, pixel);
			x++;
		}
		putchar('\n');
		y++;
		x = 0;
	}
}

void rev_grid(int rows, int cols, int grid[rows][cols])
{
	int x = 0, y = 0;

	while (grid[y][0] >= 0 && y < rows)
	{
		while (grid[y][x] >= 0 && x < cols)
		{

			switch (grid[y][x])
			{
				case 0:
					grid[y][x] = 4;
					break;

				case 1:
					grid[y][x] = 3;
					break;

				case 3:
					grid[y][x] = 1;
					break;

				case 4:
					grid[y][x] = 0;
					break;

				default:
					break;
			}
			x++;
		}
		y++;
		x = 0;
	}
}
