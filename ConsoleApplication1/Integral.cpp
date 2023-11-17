#include "Integral.h"

double f(double x) 
{
    return (1 + x * x) / (1 + pow(x, 3)); 
}
double trapezoidal(double a, double b, double epsilon)
{
    int n = 2;
    double integral_1 = 0.5 * (f(a) + f(b));
    double integral_2 = 0;
   
    while (abs(integral_1 - integral_2) > 3 * epsilon)
    {

        integral_2 = integral_1;
        double h = (b - a) / n;
        double sum = 0.0;

        for (int i = 1; i < n; i++)
        {
            sum += f(a + i * h);
        }

        integral_1 = h * (integral_1 + sum);
        n *= 2;
    }

    double R = (integral_1 - integral_2) / (pow(0.5, 2) - 1);
    cout << "Computational error R = " << R << endl;
    return integral_1;
}
double simpson(double a, double b, double epsilon)
{
    int n = 2;
    double integral_1 = (f(a) + 4 * f((a + b) / 2) + f(b)) * (b - a) / 6;
    double integral_2 = 0;


    while (abs(integral_1 - integral_2) > 15 * epsilon)
    {
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
}
    double R = (integral_1 - integral_2) / (pow(0.5, 4) - 1);
    cout << "Computational error R = " << R << endl;
    return integral_1;
}
double f(double x, double y)
{
    return 1 / pow(x + y, 2);
}
double simpsonCubature(double a, double b, double c, double d, double epsilon)
{
    double integral_1 = 0, integral_2 = 0;
   
    int n = 2, m = 2;
    double hx = (b - a) / (2 * n),
        hy = (d - c) / (2 * m);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            double x2 = a + (2 * i) * hx,
                y2 = c + (2 * j) * hy,
                x2_1 = x2 + hx,
                x2_2 = x2_1 + hx,
                y2_1 = y2 + hy,
                y2_2 = y2_1 + hy;
            integral_1 += f(x2, y2) + 4 * f(x2_1, y2) + f(x2_2, y2) + 4 * f(x2, y2_1) + 16 * f(x2_1, y2_1)
                             + 4 * f(x2_2, y2_1) + f(x2, y2_2) + 4 * f(x2_1, y2_2) + f(x2_2, y2_2);
        }
    }
    integral_1 *= hx * hy / 9;
    k++;
 
    while (abs(integral_1 - integral_2) > 15 * epsilon)
    {
        integral_1 = integral_2;
        integral_2 = 0;
        n *= 2;
        m *= 2;
        hx = (b - a) / (2 * n);
        hy = (d - c) / (2 * m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                double x2 = a + (2 * i) * hx,
                    y2 = c + (2 * j) * hy,
                    x2_1 = x2 + hx,
                    x2_2 = x2_1 + hx,
                    y2_1 = y2 + hy,
                    y2_2 = y2_1 + hy;
                integral_2 += f(x2, y2) + 4 * f(x2_1, y2) + f(x2_2, y2) + 4 * f(x2, y2_1) + 16 * f(x2_1, y2_1)
                    + 4 * f(x2_2, y2_1) + f(x2, y2_2) + 4 * f(x2_1, y2_2) + f(x2_2, y2_2);
            }
        }
        integral_2 *= hx * hy / 9;
        k++;
       
    }
    return integral_1;
}