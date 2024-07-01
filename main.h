#ifndef main_h
#define main_h

enum Print_method {
	Grid, Rows
};
void print_grid_as_pic(int rows, int cols, int grid[rows][cols], enum Print_method method);
void rev_grid(int rows, int cols, int grid[rows][cols]);

#endif
