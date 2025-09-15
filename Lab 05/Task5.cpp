#include <iostream>
using namespace std;

const int N = 9;

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Check if 'num' is not already placed in the current row
bool isRowValid(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) return false;
    }
    return true;
}

// Check if 'num' is not already placed in the current column
bool isColValid(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) return false;
    }
    return true;
}

// Check if 'num' is not already placed in the 3x3 subgrid
bool isBoxValid(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) return false;
        }
    }
    return true;
}

// Check if it is safe to place 'num' in grid[row][col]
bool isSafe(int grid[N][N], int row, int col, int num) {
    return isRowValid(grid, row, num) &&
           isColValid(grid, col, num) &&
           isBoxValid(grid, row - row % 3, col - col % 3, num);
}

// Find an empty location in the grid, store in row and col, return true if found
bool findEmptyLocation(int grid[N][N], int &row, int &col) {
    for(row = 0; row < N; row++) {
        for(col = 0; col < N; col++) {
            if(grid[row][col] == 0) return true;
        }
    }
    return false;
}

// Solve the Sudoku using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;

    // Step 1: Find empty cell
    if (!findEmptyLocation(grid, row, col)) {
        return true;  // Puzzle solved
    }

    // Step 2: Try numbers 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        // Step 3: Check if number is valid
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;  // Place number

            // Step 4: Recursive call
            if (solveSudoku(grid)) {
                return true;
            }

            // Step 5: Backtracking
            grid[row][col] = 0;  // Reset cell
        }
    }

    return false;  // Trigger backtracking
}

int main() {
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid)) {
        cout << "Sudoku solved successfully:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
