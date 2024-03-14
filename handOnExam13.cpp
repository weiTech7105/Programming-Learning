/*====================================================================================================
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n). 
If d(a) = b and d(b) = a, where a b, then a and b are an amicable pair and each of a and
b are called amicable numbers. For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; 
therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220. 
Write a program to find the sum of all the amicable numbers under 10000.

** is a != b or a could equal to b?
====================================================================================================*/
#include <iostream>
#include <iomanip>

using namespace std;

int sumOfPropDiv(int num){
    int sum = 0;
    for(int i = 1; i < num; i++){
        if(num % i == 0) sum += i;
    }
    return sum;
}

bool isAmicNum(int num1){
    int num2 = sumOfPropDiv(num1);
    return num1 != num2 && sumOfPropDiv(num2) == num1;
}

int main(){
    int sum = 0;
    
    for(int i = 1; i < 10000; i++){
        if(isAmicNum(i)){
            sum += i;
            cout << setw(5) << i;
        }
    }
    cout << endl;
    cout << "Sum of all amicable numbers under 10000: " << sum << endl;

    return 0;
}