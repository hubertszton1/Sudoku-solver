#include "sudoku.h"

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