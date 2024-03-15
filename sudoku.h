#include <stdio.h>
#include <stdlib.h>

char POSSIBLE = 0b111111111;

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
