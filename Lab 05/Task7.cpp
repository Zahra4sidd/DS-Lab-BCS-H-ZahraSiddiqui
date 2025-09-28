#include <iostream>
using namespace std;

const int N = 4;

void printGrid(char grid[N][N]) {
    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool isSafe(char grid[N][N], int row, int col){

    // column check
    for(int i=0;i<N;i++){
        if(grid[i][col] == 'Q') return false;
    }

    // row check
    for(int i=0;i<N;i++){
        if(grid[row][i] == 'Q') return false;
    }

    // both diagonals check
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(grid[i][j] == 'Q') return false;
    }
    for(int i=row, j=col; i>=0 && j<N; i--, j++){
        if(grid[i][j] == 'Q') return false;
    }

    return true;
}

void nQueenSolution(char grid[N][N], int row){
    if(row == N){
        cout<<"\nSolution:\n";
        printGrid(grid);
    }
    else{
        for(int c=0;c<N;c++){
            if(isSafe(grid, row, c)){
                grid[row][c] = 'Q';
                nQueenSolution(grid, row+1);
                grid[row][c] = '-';
            }   
        }
    }
}

int main() {
    char grid[N][N] = {
        {'-', '-', '-', '-'},
        {'-', '-', '-', '-'},
        {'-', '-', '-', '-'},
        {'-', '-', '-', '-'}
    };
    nQueenSolution(grid, 0);

    return 0;
}
