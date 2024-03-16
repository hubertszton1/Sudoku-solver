#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern char POSSIBLE;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;


typedef struct Box
{
    struct Box * next;
} Box;

typedef struct Cell
{
    int number;
    // 9 bits in variable possible
    // each bit represents wheter you can put the digit into a cell
    char code;
    int row;
    int column;
    Box * box;
} Cell;

int ** createPuzzle();
void printPuzzle(int ** puzzle);
Cell *** setUpPuzzle(int ** puzzle);

#endif
