/*=====================================================================================================
The following iterative sequence is defined for the set of positive integers:
                        n n/2(if n is even) or 3n+1(if n is odd)
  For example, using the rule above and starting with 13, we generate the following sequence:
                                13 40 20 10 5 16 8 4 2 1
  It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it
  has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1. Write
  a program to find the starting number, under 10,000, produces the longest chain.
=====================================================================================================*/

#include <iostream>

using namespace std;

int countSequence(int a){
    int count = 0;
    while(a != 1){
        if(a % 2 == 0) a = a/2;
        else a = 3 * a + 1;
        count++;
    }
    return count;
}

int main(){
    int longestNum = 0, longestCount = 0;
    for(int i = 1; i < 10000; i++){
        int currentCount = countSequence(i);
        if(currentCount > longestCount){
            longestCount = currentCount;
            longestNum = i;
        }
    }
    cout << "Number which has the longest chain : " << longestNum << "\nwhich has " << longestCount << " step." << endl;
    
    return 0;
}