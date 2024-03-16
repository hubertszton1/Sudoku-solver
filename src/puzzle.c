#include "sudoku.h"

Cell *** setUpPuzzle(int ** puzzle)
{
    Cell *** sudoku;
    int i, j, k;

    sudoku = (Cell***)malloc(sizeof(Cell**)*9);
    // loop through rows
    for (i = 0; i < SIZE_ROWS; i++)
    {
        sudoku[i] = (Cell**)malloc(sizeof(Cell*)*9);
        //loop through columns
        for (j = 0; j < SIZE_COLUMNS; j++)
        {   
            // update informations of current cell
            sudoku[i][j] = (Cell*)malloc(sizeof(Cell)*9);
            sudoku[i][j]->number = puzzle[i][j];
            sudoku[i][j]->row = i;
            sudoku[i][j]->column = j;

            sudoku[i][j]->solvable = 9;

            for (k = 0; k < SIZE_ROWS; k++)
            {
                sudoku[i][j]->possible[k] = 0;
            }
        }
    }

    for (i = 0; i < SIZE_ROWS; i++)
    {
        //loop through columns
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            if (sudoku[i][j]->number != 0)
            {
                sudoku[i][j]->solvable = 0;
                updateSudoku(sudoku, i, j);
                UNSOLVED--;
            }
        }
    }
    return sudoku;
}

int updateSudoku(Cell *** sudoku, int row, int column)
{
    int x;
    int number = sudoku[row][column]->number;

    for (x=0; x < SIZE_ROWS; x++)
    {
        if (sudoku[x][column]->possible[number - 1] == 0)
        {
            sudoku[x][column]->solvable--;
        }
        sudoku[x][column]->possible[number - 1] = 1;
    }

    for (x=0; x < SIZE_COLUMNS; x++)
    {
        if (sudoku[row][x]->possible[number - 1] == 0)
        {
            sudoku[row][x]->solvable--;
        }
        sudoku[row][x]->possible[number - 1] = 1;
    }

    return 1;
}

int checkPuzzle(Cell *** sudoku)
{
    int i, j, k;

    for (i = 0; i < SIZE_ROWS; i++)
    {
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            if (sudoku[i][j]->solvable == 1)
            {
                solveCell(sudoku[i][j]);
                updateSudoku(sudoku, i, j);
            }
        }
    }
    return 1;
}

int ** createPuzzle(){
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

void printPuzzle(Cell *** puzzle)
{
    int i, j;

    printf("\n-------------------------------\n");
    // iterate through all rows
    for (i = 0; i < SIZE_ROWS; i++)
    {   
        printf("|");
        // iterate through each cell in a row
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            printf(" %d ", puzzle[i][j]->number);
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