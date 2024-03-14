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

vector<int> findLuckyNumbers(vector<vector<int > >& matrix){
    int ROW = matrix.size();
    int COL = matrix[0].size();
    vector<int> luckyNumbers;
    vector<int> rowMin (ROW, INT_MAX);
    vector<int> colMax (COL, INT_MIN);

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j< COL; j++){
            rowMin[i] = min(rowMin[i], matrix[i][j]);
        }
    }

    for(int j = 0; j < COL; j++){
        for(int i = 0; i < ROW; i++){
            colMax[j] = max(colMax[j], matrix[i][j]);
        }
    }

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(colMax[j] == matrix[i][j] && rowMin[i] == matrix[i][j])
                luckyNumbers.push_back(matrix[i][j]);
        }
    }

    return luckyNumbers;
}

int main(){
    int M, N;
    cout << "Please enter the dimensions of the matrix(M and N) : ";
    cin >> M >> N;
    vector<vector<int > > matrix (M, vector<int>(N, 0)); //intialize a matrix which has M rows and N cols and 0 of all elements

    cout << "Please enter the elements of the matrix : ";
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }

    vector<int> luckyNumbers = findLuckyNumbers(matrix);
    if(luckyNumbers.empty()) cout << "There's no lucky numbers in the matrix.";
    else{
        for(size_t i = 0; i < luckyNumbers.size(); i++){
            cout << luckyNumbers[i] << "  ";
        }
    }
    cout << endl;

    return 0;
}