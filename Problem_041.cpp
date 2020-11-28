// { Driver Code Starts

// Sudoku
// backtracking
// complexity - 9^81

/*
    1. First check for empty location if not present return true sudoku solved
    2. for an empty location create a loop from 1 to 9 and check if a number is valid
        or not by checking row and coluumn and grid
    3. if valid update grid and call sudoku recursilvely
    4. else check for next number

    checking before putting a number makes huge difference in run time in general case

*/
#include <bits/stdc++.h>
using namespace std;
#define DEVESH 1
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

int calls = 0;
bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

int main() {
#ifdef DEVESH
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        if (SolveSudoku(grid) == true)
            printGrid(grid);
        else
            cout << "No solution exists";



        // cout << calls << "\n";
        cout << endl;

    }

    return 0;
}// } Driver Code Ends

bool checkRow(int r, int num, int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        if (grid[r][i] == num)
            return false;
    }
    return true;
}

bool checkCol(int c, int num, int grid[N][N])
{
    //check if given column is valid

    for (int j = 0; j < N; j++)
    {
        if (grid[j][c] == num)
            return false;
    }

    return true;
}

bool checkGrid(int row, int col, int num, int grid[N][N])
{
// check if given grid are ok
    for (int k = 0; k < 3; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            if (grid[row + k][col + l] == num)
                return false;
        }
    }

    return true;
}

bool location(int& row, int& col , int grid[N][N])
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;
    return false;

}

bool SolveSudoku(int grid[N][N])
{


    // printGrid(grid);
    // cout << endl << endl;
    int i, j;

    if (!location(i, j, grid))
        return true;


    for (int k = 1; k < 10; k++)
    {
        if (checkRow(i, k, grid) && checkCol(j, k, grid)
                && checkGrid(3 * (i / 3), 3 * (j / 3), k, grid))
        {
            grid[i][j] = k;
            if (SolveSudoku(grid))
                return true;
            grid[i][j] = 0;
        }
    }
    return false;
}

void printGrid (int grid[N][N])
{
    // Your code here ;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
}
