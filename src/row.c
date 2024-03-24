#include "sudoku.h"

int checkRows(Cell *** sudoku, Box ** boxes)
{
    int i, j, k;
    int sum[9];
    int place[9];
    // loop through all rows
    for (i = 0; i < 9; i++)
    {   
        // initialize sum and place to zeroes
        for (j = 0; j < 9; j++)
        {   
            place[j] = 0;
            sum[j] = 0;
        }
        // loop through each cell in the row
        for (j = 0; j < 9; j++)
        {
            if (sudoku[i][j]->number != 0)
            {
                continue;
            }

            // loop through all possibles
            for(k = 0; k < 9; k++)
            {   
                // check if number {k} is possible
                if (sudoku[i][j]->possible[k] == 0)
                {
                    sum[k]++;
                    place[k] = j;
                }
            }
        }

        for (j = 0; j < 9; j++)
        {
            if (sum[j] == 1)
            {
                sudoku[j][place[k]]->number = k + 1;
                sudoku[j][place[k]]->solvable = 0;
                UNSOLVED--;

                updateSudoku(sudoku, i, place[k]);
                updateBoxes(sudoku, i, place[k]);
                return 1;
            }
        }

    }

    return 0;
}