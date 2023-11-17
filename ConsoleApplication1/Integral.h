#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

double trapezoidal(double a, double b, double epsilon);
double simpson(double a, double b, double epsilon);
double simpsonCubature(double a, double b, double c, double d, double E);