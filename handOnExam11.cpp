/*========================================================================================
A narcissistic number is a positive integer which is equal to its digits sum 
raised to the number of digits in the integer. For example, the integer 153 is a 
narcissistic number because 153 = 1^3 + 5^3 + 3^3. 
Write a program to find all the narcissistic numbers between 100 to 99999.
========================================================================================*/
#include <iostream>
#include <iomanip>

using namespace std;

int countDigit(int num){
    int count = 0;
    while(num > 0){
        count++;
        num /= 10;
    }
    return count;
}


bool isNarcissis(int num){
    int sum = 0;
    int originalNum = num;
    int digit = countDigit(num);

    while(num > 0){
        sum += pow(num % 10, digit);
        num /= 10;
    }

    return sum == originalNum;
}

int main(){
    for(int i = 100; i < 100000; i++){
        if(isNarcissis(i)) cout << setw(6) << i;
    }
    cout << endl;

    return 0;
}