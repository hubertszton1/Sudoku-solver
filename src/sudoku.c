#include "sudoku.h"

int main(){

    int ** puzzle;
    Cell *** sudoku;
    puzzle = createPuzzle();

    printPuzzle(puzzle);

    sudoku = setUpPuzzle(puzzle);
    return 0;
}