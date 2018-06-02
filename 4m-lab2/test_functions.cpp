#include "test_functions.h"

#define _USE_MATH_DEFINES
#include <cmath>

double func_u(double x, double y)
{
    double pi = M_PI;

    // 1 вариант
    // return exp(pow(sin(pi*x*y), 2.0));

    // 5 вариант
    return exp(pow(sin(pi*x*y), 2.0));
}

double func_f1(double x, double y)
{
    double pi = M_PI;

    // 1 вариант
    // return -2.0*pi*pi*(x*x + y * y)*exp(pow(sin(pi*x*y), 2.0))*((2.0*pow(sin(pi*x*y), 2.0) + 1.0)*pow(cos(pi*x*y), 2.0) - pow(sin(pi*x*y), 2.0));

    // 5 вариант
    return -2.0*pi*pi*(x*x + y*y)*exp(pow(sin(pi*x*y), 2.0))*((2.0*pow(sin(pi*x*y), 2.0) + 1.0)*pow(cos(pi*x*y), 2.0) - pow(sin(pi*x*y), 2.0));
}
