/*=====================================================================================================
Design a function that estimates the value of e^x by using the following formula for n = 20. Use a
main function to call this function and compute the values of e^1, e^2, e^3, e^4, ... , e^10. Display your
results on the computer screen.
e^x = 1 + x + x^2/2! + x^3/3! + ...x^n/n!
=====================================================================================================*/
#include <iostream>
#include <iomanip>

using namespace std;

double calculateEuler(double x, int n){
    double result = 1.0;
    double deno = 1.0;
    for(int i = 1; i <= n; i++){
        deno *= i;
        result += pow(x, i)/deno;
    }
    return result;
}

int main(){
    const int N = 20;

    for(double i = 1.0; i <= 10.0; i++)
        cout << "The answer of e^" << i << " is : " << calculateEuler(i, N) << endl;

    return 0;
}