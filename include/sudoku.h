#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>
// 
extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

// structs declarations
typedef struct Box
{
    struct Box * next;
} Box;

typedef struct Cell
{
    int number;
    // 9 bits in variable possible
    // each bit represents wheter you can put the digit into a cell
    int possible[9];
    int solvable;
    int row;
    int column;
    Box * box;
} Cell;


// functions declarations
int ** createPuzzle();
void printPuzzle(Cell *** puzzle);
Cell *** setUpPuzzle(int ** puzzle);
int updateSudoku(Cell *** sudoku, int row, int column);
int checkPuzzle(Cell *** sudoku);
int solveCell(Cell * cell);

#endif
