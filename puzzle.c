#include "sudoku.h"

int ** create_puzzle(){
    int ** puzzle;
    int i, j;
    int array[9][9] = { 0, 0, 1,   7, 6, 0,    9, 0, 0,
                        8, 2, 0,   0, 0, 0,    0, 0, 3,
                        0, 4, 9,   0, 0, 1,    0, 0, 0,

                        2, 0, 0,   9, 3, 0,    7, 0, 0,
                        0, 0, 6,   0, 1, 7,    0, 3, 0,
                        0, 0, 0,   0, 2, 0,    0, 0, 0,
                
                        0, 0, 0,   0, 0, 5,    0, 0, 8,
                        0, 0, 0,   6, 0, 0,    0, 0, 0,
                        0, 7, 0,   0, 0, 0,    5, 0, 1};

    // allocate memory for two-dimensional array of size 9x9
    puzzle = (int**)malloc(sizeof(int*)*9);

    for (i = 0; i < 9; i++)
    {
        puzzle[i] = (int*)malloc(sizeof(int)*9);

        // copy values from array to puzzle
        for (j = 0; j < 9; j++)
        {
            puzzle[i][j] = array[i][j];
        }
    }

    return puzzle;
}

void print_puzzle(int ** puzzle)
{
    int i, j;

    printf("\n-------------------------------\n");
    // iterate through all rows
    for (i = 0; i < 9; i++)
    {   
        printf("|");
        // iterate through each cell in a row
        for (j = 0; j < 9; j++)
        {
            printf(" %d ", puzzle[i][j]);
            if ((j+1) % 3 == 0)
            {
                printf("|");
            }
        }
        printf("\n");
        if ((i+1) % 3 == 0)
        {
            printf("-------------------------------\n");
        }
    }
}