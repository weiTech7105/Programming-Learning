#include <iostream>
#include <climits>

using namespace std;

const int MAX_SIZE = 10;

// Function to find lucky numbers
void findLuckyNumbers(int matrix[MAX_SIZE][MAX_SIZE], int M, int N, int luckyNumbers[], int& count) {
    count = 0; // Initialize count of lucky numbers to 0

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            bool isLucky = true;
            int element = matrix[i][j];

            // Check if element is the minimum in its row
            for (int k = 0; k < N; ++k) {
                if (matrix[i][k] < element) {
                    isLucky = false;
                    break;
                }
            }

            // Check if element is the maximum in its column
            for (int k = 0; k < M && isLucky; ++k) {
                if (matrix[k][j] > element) {
                    isLucky = false;
                    break;
                }
            }

            if (isLucky) {
                luckyNumbers[count++] = element;
            }
        }
    }
}

int main() {
    int M, N;
    cout << "Enter the dimensions of the matrix (M and N): ";
    cin >> M >> N;

    int matrix[MAX_SIZE][MAX_SIZE];
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    int luckyNumbers[MAX_SIZE];
    int count = 0;
    findLuckyNumbers(matrix, M, N, luckyNumbers, count);
    cout << "Lucky numbers in the matrix are: ";
    for (int i = 0; i < count; ++i) {
        cout << luckyNumbers[i] << " ";
    }
    cout << endl;

    return 0;
}
