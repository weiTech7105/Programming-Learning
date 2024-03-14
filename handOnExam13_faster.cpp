/*====================================================================================================
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n). 
If d(a) = b and d(b) = a, where a b, then a and b are an amicable pair and each of a and
b are called amicable numbers. For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; 
therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220. 
Write a program to find the sum of all the amicable numbers under 10000.

** is a != b or a could equal to b?
====================================================================================================*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int sumOfDivisors(int n) {
    int sum = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            int d = n / i;
            if (d != i && d != n) {
                sum += d;
            }
        }
    }
    return sum;
}

int main() {
    const int limit = 10000;
    int totalSum = 0;

    for (int a = 2; a < limit; a++) {
        int b = sumOfDivisors(a);

        // Check if b is amicable with a, but only if b is within limit and not equal to a
        if (b < limit && a != b && sumOfDivisors(b) == a) {
            totalSum += a;
            cout << setw(5) << a;
        }
    }

    cout << "\nSum of all amicable numbers under 10000: " << totalSum << endl;

    return 0;
}