/*======================================================================================================
A pair of positive integer numbers are called twin primes if they are both prime numbers 
and the difference between them is 2, i.e., they are consecutive odd numbers and they are 
prime numbers. (3, 5), (5, 7) and (11, 13) are three examples of such pair of twin prime numbers. 
Write a program to display all the pairs of twin prime numbers that are less than 1000.
======================================================================================================*/
#include <iostream>

using namespace std;

bool isPrime(int Num, int i = 2){
    if(Num <= 2){
        if(Num == 2) return true;
        else return false;
    }
    if(Num % i == 0) return false;
    if(i * i > Num) return true;

    return isPrime(Num, i + 1);
}

int main(){
    int primeNum1 = 0, primeNum2 = 0;

    for(int i = 2; i < 1000; i++){
        if(isPrime(i)) {
            if(i == 2) primeNum2 = 2;
            else{
                primeNum1 = primeNum2;
                primeNum2 = i;
                if(primeNum2 - primeNum1 == 2) 
                    cout << "(" << primeNum1 << ", " << primeNum2 << ")" << endl;
            }
        }
    }
    return 0;
}