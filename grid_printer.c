#include "main.h"
#include <stdio.h>

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
void print_grid_as_pic(int rows, int cols, int grid[rows][cols], enum Print_method method)
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
			/*if (cols < 250)
				*/printf("%c%c%c", pixel, pixel, (method == Grid) ? ' ' : pixel);
			/*else
				printf("%c", pixel);*/
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
