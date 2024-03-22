#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>
// 
extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

// structs declarations
typedef struct Sudoku
{
    struct Cell *** cells;
    struct Box ** boxes;
} Sudoku;

typedef struct Box
{   
    struct Cell ** cells;
    int numbers;
    int possible[9];
    int solvable;
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
Sudoku * setUpPuzzle(int ** puzzle);
Sudoku * createSudoku(Cell *** cells, Box ** boxes);
int updateSudoku(Cell *** sudoku, int row, int column);
int checkPuzzle(Cell *** sudoku);
int solveCell(Cell * cell);
Box ** createBoxes();
int updateBoxes(Cell *** sudoku, int row, int column);

#endif
