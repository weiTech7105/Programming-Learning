/*======================================================================================================
Design a function that calculates the greatest common divisor (GCD) and the least common
multiple (LCM) of two positive integers. Use a main function to call this function. The main
function needs to ask the user to input the two integers repeatedly until the user responses 
to end the program.
======================================================================================================*/

#include <iostream>

using namespace std;

int gcd(int num1, int num2){
    if(num2 == 0) return num1;
    else return gcd(num2, num1 % num2);
}

int lcm(int num1, int num2){
    return (num1 * num2) / gcd(num1, num2);
}

int main(){
    int num1 = 0, num2 = 0;

    cout << "Please enter two integers : ";
    while(cin >> num1 >> num2){
        cout << "\nthe gcd of the integers is : " << gcd(num1, num2) << "; while lcm is : " << lcm(num1, num2);
        cout << "\nPlease enter two integers, if you want to exit please press CTRZ-Z : ";
    }

    return 0;
}