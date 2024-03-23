#include "sudoku.h"

int boxSingles(Cell *** sudoku, Box ** boxes)
{
    int i, j, k;
    int count;
    int temp;

    // loop through boxes
    for (i = 0; i < 9; i++)
    {
        // loop through possible array
        for (j = 0; j < 9; j++)
        {
            count = 0;

            // loop through squares
            for (k = 0; k < 9; k++)
            {
                if (boxes[i]->cells[k]->number != 0)
                    continue;
                if (boxes[i]->cells[k]->possible[j] == 0)
                {
                    count++;
                    temp =  k;
                }

                if (count == 2)
                {
                    break;
                }
                
            }

            if (count == 1)
            {
                boxes[i]->cells[temp]->number = j + 1;
                UNSOLVED--;
                boxes[i]->cells[temp]->solvable = 0;
                
                updateSudoku(sudoku, boxes[i]->cells[temp]->row, boxes[i]->cells[temp]->column);

                return 1;
            }
        }

    }

    return 0;
}

Box ** createBoxes()
{
    int x, y;
    Box ** boxes;
    boxes = malloc(sizeof(Box*)*9);

    for (x = 0; x < 9; x++)
    {
        boxes[x] = malloc(sizeof(Box));
        boxes[x]->cells = malloc(sizeof(Cell*)*9);
        boxes[x]->numbers = 0;
        boxes[x]->solvable = 9;
        
        for (y = 0; y < 9; y++)
        {
            boxes[x]->possible[y] = 0;
        }
    }

    return boxes;
}

int updateBoxes(Cell *** sudoku, int row, int column)
{
    int x;
    int number = sudoku[row][column]->number;
    Box * box;
    box = sudoku[row][column]->box;

    for (x = 0; x < 9; x++)
    {
        if (box->cells[x]->possible[number-1] == 0)
        {
            box->cells[x]->solvable--;
            box->cells[x]->possible[number-1] = 1;
        }
    }
}