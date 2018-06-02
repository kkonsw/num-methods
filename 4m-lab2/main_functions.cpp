#include "main_functions.h"

#define _USE_MATH_DEFINES
#include <cmath>

double func_f2(double x, double y)
{
    double pi = M_PI;

    // 1 вариант
    //return -(pow(sin(pi*x*y), 2));

    // 5 вариант
    //return -fabs(x - y);

    // тестовая задача
    //return -2.0*pi*pi*(x*x + y*y)*exp(pow(sin(pi*x*y), 2.0))*((2.0*pow(sin(pi*x*y), 2.0) + 1.0)*pow(cos(pi*x*y), 2.0) - pow(sin(pi*x*y), 2.0));

    // 7 вариант
    return -fabs(x*x - 2 * y);

    // 10 вариант
    //return (exp(x*x*y) + exp(-x*x*y)) / 2.0;
}

double nu1(double y)
{
    double pi = M_PI;

    //1 вариант
    //return sin(pi*y);

    // 5 вариант
    //return -y * (y - 1);

    // 7 вариант
    return pow(sin(pi*y), 2.0);

    // тестовая задача
    //return 1.0;

    // 10 вариант
    //return sin(pi*y);
}

double nu2(double y)
{
    double pi = M_PI;

    //1 вариант
    //return sin(pi*y);

    // 5 вариант
    //return y * (1 - y); 

    // 7 вариант
    return pow(sin(2.0*pi*y), 2.0);

    // тестовая задача
    //return exp(pow(sin(pi * 2 * y), 2.0));

    // 10 вариант
    //return fabs(sin(2*pi*y));
}

double nu3(double x)
{
    double pi = M_PI;

    //1 вариант
    //return x - x * x;

    // 5 вариант
    //return fabs(sin(pi*x));

    // 7 вариант
    return pow(sin(pi*x), 2.0);

    // тестовая задача
    //return 1.0;

    // 10 вариант
    //return -x * (x + 1);
}

double nu4(double x)
{
    double pi = M_PI;

    //1 вариант
    //return x - x * x;

    // 5 вариант
    //return fabs(sin(pi*x)) * exp(x);

    // 7 вариант
    return pow(sin(2.0*pi*x), 2.0);

    // тестовая задача
    //return exp(pow(sin(pi * x), 2.0));

    // 10 вариант
    //return -x * (x + 1);
}
