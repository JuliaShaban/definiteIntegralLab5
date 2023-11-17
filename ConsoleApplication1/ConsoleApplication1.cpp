#include "Integral.h"

int main() {
    double a = 3.0, b = 4.254, a2 = 3.0, b2 = 4.0, c = 1.0, d = 2.0;
    double epsilon[] = { 1e-4, 1e-5 }; 

    for (int i = 0; i < 2; i++)
    {
        cout << "Trapezoid method with epsilon = " << epsilon[i] << ": " << trapezoidal(a, b, epsilon[i]) << endl;
        cout << "Simpson's method with epsilon = " << epsilon[i] << ": " << simpson(a, b, epsilon[i]) << endl;
        cout << "Cubator Simpson's method with epsilon = " << epsilon[i] << ": " << simpsonCubature(a2 ,b2 ,c ,d , epsilon[i]) << endl;
    }

    return 0;
}
