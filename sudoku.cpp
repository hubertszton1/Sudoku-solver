#include <iostream>
using namespace std;

#define N 9

// Bitmasks for each row/column/Box
int row[N], col[N], box[N];
bool seted = false;

// function to check box index for i,j position in the grid
int getBox(int i, int j)
{
    return i/3 * 3 + j/3;   
}

// function to check if given number is placed in corresponding row/column/box
bool isSafe(int i, int j, int number)
{
    bool safeRow = !((row[i] >> number) & 1);
    bool safeCol = !((col[j] >> number) & 1);
    bool safeBox = !((box[getBox(i, j)] >> number) & 1);
    return safeRow && safeCol && safeBox;
}

// function to set initial state of sudoku board
void setInitialState(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            row[i] |= 1 << grid[i][j];
            col[j] |= 1 << grid[i][j];
            box[getBox(i, j)] |= 1 << grid[i][j];
        }
    }
}

bool solveSudoku(int grid[N][N], int i, int j)
{
    // set the initial state
    if (!seted)
    {   
        seted = true, setInitialState(grid);
    }
    // check if it is the end of sudoku board
    if (i == N - 1 && j == N)
        return true;
    
    // go through all the cells from left to right and go to the next row
    if (j == N)
    {
        j = 0;
        i++;
    }
    // if there is already number placed in position i,j go to the next cell
    if (grid[i][j])
        return solveSudoku(grid, i, j+1);
    
    for (int nr = 1; nr <= N; nr++)
    {
        if (isSafe(i, j, nr))
        {
            // assign nr in the current (i,j) position
            // add nr to each bitmask
            grid[i][j] = nr;
            row[i] |= 1 << nr;
            col[j] |= 1 << nr;
            box[getBox(i, j)] |= 1 << nr;

            // return True if solution is right
            if (solveSudoku(grid, i, j+1))
                return true;

            // if solution is wrong
            // remove nr from each bitmask and search for another solution
            row[i] &= ~(1 << nr);
            col[j] &= ~(1 << nr);
            box[getBox(i, j)] &= ~(1 << nr);
        }

        grid[i][j] = 0;
    }
    return false;  
}

// function to print solved grid
void print(int grid[N][N])
{
    cout << "\n-------------------------------\n";
    for (int i = 0; i < N; i++)
    {
        cout << "|";
        for (int j = 0; j < N; j++)
        {
            cout << " " << grid[i][j] << " ";
            if ((j+1) % 3 == 0)
                cout << "|";
        }
        cout << endl;
        if ((i+1) % 3 == 0)
            cout << "-------------------------------\n";
    }
}

int main()
{
    // 0 means unassigned cells
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if (solveSudoku(grid, 0, 0))
        print(grid);
    else
        cout << "No solution exists\n";

    return 0;
}