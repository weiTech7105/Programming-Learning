/*========================================================================================
Design a function for matrix multiplication. The two input matrices are A (M*L) and B (L*N), 
and the result is matrix C (M*N, C = A * B). You need to use dynamic memory allocation approach 
(pointer) to solve this problem. Also write a main program to test your function.
========================================================================================*/
#include <iostream>

using namespace std;

// Function to allocate memory for a matrix
double** allocateMatrix(int rows, int cols) {
    double** matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[cols];
    }
    return matrix;
}

// Function to deallocate memory of a matrix
void freeMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Function to multiply two matrices
double** multiplyMatrices(double** A, int A_rows, int A_cols, double** B, int B_rows, int B_cols) {
    if (A_cols != B_rows) {
        // Matrices cannot be multiplied due to incompatible dimensions
        return nullptr;
    }

    double** C = allocateMatrix(A_rows, B_cols);

    for (int i = 0; i < A_rows; i++) {
        for (int j = 0; j < B_cols; j++) {
            C[i][j] = 0;
            for (int k = 0; k < A_cols; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Main program
int main() {
    int A_rows = 2, A_cols = 3;
    int B_rows = 3, B_cols = 2;

    double** A = allocateMatrix(A_rows, A_cols);
    double** B = allocateMatrix(B_rows, B_cols);

    // Initialize matrix A with values
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;

    // Initialize matrix B with values
    B[0][0] = 7; B[0][1] = 8;
    B[1][0] = 9; B[1][1] = 10;
    B[2][0] = 11; B[2][1] = 12;

    double** C = multiplyMatrices(A, A_rows, A_cols, B, B_rows, B_cols);
    if (C == nullptr) {
        cerr << "Error: Matrices cannot be multiplied due to incompatible dimensions\n";
    } else {
        cout << "Matrix C (Result):" << endl;
        printMatrix(C, A_rows, B_cols);

        freeMatrix(C, A_rows); // Free memory allocated for C
    }

    freeMatrix(A, A_rows); // Free memory allocated for A
    freeMatrix(B, B_rows); // Free memory allocated for B

    return 0;
}