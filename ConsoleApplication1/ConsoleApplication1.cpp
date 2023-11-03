#include "Integral.h"

int main() {
    double a = 3.0; 
    double b = 4.254; 
    double epsilon[] = { 1e-4, 1e-5 }; 

    for (int i = 0; i < 2; i++)
    {
        cout << "Trapezoid method with epsilon = " << epsilon[i] << ": " << trapezoidal(a, b, epsilon[i]) << endl;
        cout << "Simpson's method with epsilon = " << epsilon[i] << ": " << simpson(a, b, epsilon[i]) << endl;
    }

    return 0;
}
