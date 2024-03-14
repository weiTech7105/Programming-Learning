/*======================================================================================================
Design a function with an input of M×N matrix (M ≤ 10, N ≤ 10) of distinct integer numbers and
return all lucky numbers in the matrix in any order. A lucky number is an element of the matrix
such that it is the minimum element in its row and maximum in its column. For example, 15 is a 
lucky number in the matrix [[3,7,8], [9,11,13], [15,16,17]]. Use a main function to ask user to input
the M×N matrix, call this function, and output the result on the screen.
======================================================================================================*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> findLuckyNumbers(vector<vector<int > >& matrix) {
    int ROW = matrix.size();
    int COL = matrix[0].size();
    vector<int> rowMins(ROW, INT_MAX);
    vector<int> colMaxs(COL, INT_MIN);
    vector<int> luckyNumbers;

    // Precompute the minimum of each row
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            rowMins[i] = min(rowMins[i], matrix[i][j]);
        }
    }

    // Precompute the maximum of each column
    for (int j = 0; j < COL; ++j) {
        for (int i = 0; i < ROW; ++i) {
            colMaxs[j] = max(colMaxs[j], matrix[i][j]);
        }
    }

    // Find lucky numbers
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (matrix[i][j] == rowMins[i] && matrix[i][j] == colMaxs[j]) {
                luckyNumbers.push_back(matrix[i][j]);
            }
        }
    }

    return luckyNumbers;
}

int main() {
    int M, N;
    cout << "Please enter the dimensions of the matrix (M and then N): ";
    cin >> M >> N;

    vector<vector<int > > matrix(M, vector<int>(N));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> luckyNums = findLuckyNumbers(matrix);
    if (luckyNums.empty()) {
        cout << "There's no Lucky Number in this matrix." << endl;
    } else {
        cout << "Lucky Numbers in this matrix are: ";
        for (size_t num = 0; num < luckyNums.size(); num++) {
            cout << luckyNums[num] << " ";
        }
        cout << endl;
    }

    return 0;
}
