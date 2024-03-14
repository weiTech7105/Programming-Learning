/*======================================================================================================
Design a program that computes the roots of a quadratic equations with one unknown: 
                                    ax^2+bx+c=0
The user inputs are the coefficients of the equation: a, b, and c. The program needs 
to give the root or roots of the equation based on the value of b^2 – 4ac.
======================================================================================================*/
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double a = 0.0, b = 0.0, c = 0.0;
    cout << "Please enter the number a, b and c in the equation ax^2+bx+c=0 to solve the x : ";
    cin >> a >> b >> c;

    double D = pow(b, 2) - 4 * a * c;
    if(D < 0) cout << "There's no real roots of this quadratic equation.\n";
    else if(D == 0) cout << "There's one root of this quadratic : " << (-b / (2 * a)) << endl;
    else {
        double sqrtD = sqrt(D);                                             // Calculate the square root of D
        cout << "There are two real roots for this quadratic equation: ";
        cout << (-b + sqrtD) / (2 * a) << " and " << (-b - sqrtD) / (2 * a) << endl;
    }

    return 0;
}

