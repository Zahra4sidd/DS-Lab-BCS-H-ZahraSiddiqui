#include <iostream>
using namespace std;

int** addMatrices(int** a,int** b,int rows,int cols){
    int** result = new int*[rows];
    for(int i=0;i<rows;i++){
        result[i] = new int[cols];
        for(int j=0;j<cols;j++){
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

int** subtractMatrices(int** a,int** b,int rows,int cols){
    int** result = new int*[rows];
    for(int i=0;i<rows;i++){
        result[i] = new int[cols];
        for(int j=0;j<cols;j++){
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}

void printMatrix(int** mat,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteMatrix(int** mat,int rows){
    for(int i=0;i<rows;i++){
        delete[] mat[i];
    }
    delete[] mat;
}

int main(){
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    int** A = new int*[rows];
    int** B = new int*[rows];

    for(int i=0;i<rows;i++){
        A[i] = new int[cols];
        B[i] = new int[cols];
    }
    cout << "Enter elements of Matrix A:\n";
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            cin >> A[i][j];
    cout << "Enter elements of Matrix B:\n";
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            cin >> B[i][j];
    int** sum = addMatrices(A,B,rows,cols);
    int** diff = subtractMatrices(A,B,rows,cols);
    cout << "Sum of matrices:\n";
    printMatrix(sum,rows,cols);
    cout << "Difference of matrices:\n";
    printMatrix(diff,rows,cols);

    deleteMatrix(A,rows);
    deleteMatrix(B,rows);
    deleteMatrix(sum,rows);
    deleteMatrix(diff,rows);

    return 0;
}
