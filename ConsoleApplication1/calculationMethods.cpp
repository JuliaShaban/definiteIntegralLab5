#include "Integral.h"

double f(double x) 
{
    return (1 + x * x) / (1 + pow(x, 3)); 
}
double trapezoidal(double a, double b, double epsilon)
{
    int n = 2;
    double integral_1 = 0.5 * (f(a) + f(b));
    double integral_2 = integral_1;

    do {
        integral_2 = integral_1;
        double h = (b - a) / n;
        double sum = 0.0;

        for (int i = 1; i < n; i++) 
        {
            sum += f(a + i * h);
        }

        integral_1 = h * (integral_1 + sum);
        n *= 2;

    } while (abs(integral_1 - integral_2) >= 3 * epsilon);
    double R = (integral_1 - integral_2) / (pow(0.5, 2) - 1);
    cout << "Computational error R = " << R << endl;
    return integral_1;
}
double simpson(double a, double b, double epsilon) 
{
    int n = 2;
    double integral_1 = (f(a) + 4 * f((a + b) / 2) + f(b)) * (b - a) / 6;
    double integral_2 = integral_1;

    do {
        integral_2 = integral_1;
        double h = (b - a) / n;
        double sum = 0.0;

        for (int i = 1; i < n; i++) 
        {
            double x = a + i * h;
            sum += 4 * f(x - h / 2) + 2 * f(x);
        }

        integral_1 = (f(a) + f(b) + sum) * h / 6;
        n *= 2;

    } while (abs(integral_1 - integral_2) >= 15 * epsilon);
    double R = (integral_1 - integral_2) / (pow(0.5, 4) - 1);
    cout << "Computational error R = " << R << endl;
    return integral_1;
}