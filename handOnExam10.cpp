/*========================================================================================
Write a program that simulates the rolling of two dice. 
Your program should roll the dice 100,000 times. Use a 1-dimensional array 
to tally the numbers of times each possible value from 1 to 12, and display the results on the screen.
========================================================================================*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;
int rollDice(){
    int count = ((rand() % 6) + 1) + ((rand() % 6) + 1);
    return count;
}

int main(){
    int countArray[12] = {0};
    srand(time(0));

    for(int i = 0; i < 100000; i++){
        int count = rollDice();
        countArray[count - 1]+= 1;
    }

    for(int i = 1; i <= 12; i++)
        cout << setw(7) << i;
    cout << endl;
    for(int i = 0; i < 12; i++)
        cout << setw(7) << countArray[i];
    cout << endl;

    return 0;
}