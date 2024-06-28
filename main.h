#ifndef main_h
#define main_h

typedef struct grid {
	int height;
	int width;

	int *grid[];
} grid_t ;

void print_grid_as_pic(int rows, int cols, int grid[rows][cols]);
void print_grid_2(grid_t grid);

#endif
