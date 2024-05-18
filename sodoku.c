#include "sodoku.h"
#include <stdio.h>

void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            printf("%2d", grid[row][col]);
        printf("\n");
    }
}

bool findUnassignedLocation(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (grid[*row][*col] == UNASSIGNED)
                return true;
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int d = 0; d < N; d++)
        if (grid[row][d] == num || grid[d][col] == num)
            return false;
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;
    return true;
}

bool solveSudoku(int grid[N][N]) {
    int row, col;
    if (!findUnassignedLocation(grid, &row, &col))
        return true; 
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
        }
    }
    return false; 
}
