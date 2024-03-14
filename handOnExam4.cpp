/*======================================================================================================
Design a function with an input of M×N matrix (M ≤ 10, N ≤ 10) of distinct integer numbers and
return all lucky numbers in the matrix in any order. A lucky number is an element of the matrix
such that it is the minimum element in its row and maximum in its column. For example, 15 is a 
lucky number in the matrix [[3,7,8], [9,11,13], [15,16,17]]. Use a main function to ask user to input
the M×N matrix, call this function, and output the result on the screen.
======================================================================================================*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findLuckyNumbers(vector<vector<int> >& matrix) {
	vector<int> luckyNumbers;
    if (matrix.empty() || matrix[0].empty()) return luckyNumbers;

    int M = matrix.size();
    int N = matrix[0].size();

    for (int i = 0; i < M; i++) {
        if (matrix[i].size() != N) {
            return luckyNumbers;
        }

        for (int j = 0; j < N; j++) {
            int rowMin = *min_element(matrix[i].begin(), matrix[i].end());
            int colMax = matrix[0][j];
            for (int k = 1; k < M; k++) {
                colMax = max(colMax, matrix[k][j]);
            }

            if (matrix[i][j] == rowMin && matrix[i][j] == colMax) {
                luckyNumbers.push_back(matrix[i][j]);
            }
        }
    }

    return luckyNumbers;
}
	
int main() {
	int M, N;
	cout << "Enter the dimensions of the matrix (M and N): ";
	cin >> M >> N;
	vector<vector<int> > matrix(M, vector<int>(N));
	cout << "Enter the elements of the matrix:";
	for (int i = 0; i < M; i++) {
	    for (int j = 0; j < N; j++) {
	        cin >> matrix[i][j];
	    }
	}
    
	vector<int> luckyNumbers = findLuckyNumbers(matrix);

	cout << "Lucky numbers in the matrix are: ";
    for (size_t i = 0; i < luckyNumbers.size(); i++) {
        cout << luckyNumbers[i] << " ";
    }
	cout << endl;

	return 0;
}