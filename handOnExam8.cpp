/*======================================================================================================
A pair of positive integer numbers are called twin primes if they are both prime numbers 
and the difference between them is 2, i.e., they are consecutive odd numbers and they are 
prime numbers. (3, 5), (5, 7) and (11, 13) are three examples of such pair of twin prime numbers. 
Write a program to display all the pairs of twin prime numbers that are less than 1000.
======================================================================================================*/
#include <iostream>

using namespace std;

bool isPrime(int num){
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0) return false;
    }
    return true;
}
int main(){
    int num1 = 0, num2 = 0;
    int count = 0;
    for(int i = 2; i < 1000; i++){
        if(isPrime(i)){
            if(i == 2) num2 = 2;
            else{
                num1 = num2;
                num2 = i;
                if(num2 - num1 == 2) {
                    if(count % 8 == 0 && count != 0) cout <<  "(" << num1 << ", " << num2 << ")" << "  " << endl;
                    else cout << "(" << num1 << ", " << num2 << ")" << "  ";
                    count++;
                }
            }
        }
    }
    return 0;
}