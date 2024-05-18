#ifndef SUDOKU_H
#define SUDOKU_H

#define UNASSIGNED 0
#define N 9

#include <stdbool.h>

void printGrid(int grid[N][N]);
bool solveSudoku(int grid[N][N]);
bool findUnassignedLocation(int grid[N][N], int *row, int *col);
bool isSafe(int grid[N][N], int row, int col, int num);

#endif
