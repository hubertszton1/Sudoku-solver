#include "sudoku.h"

int main(){

    int ** puzzle;
    puzzle = create_puzzle();

    print_puzzle(puzzle);
    return 0;
}