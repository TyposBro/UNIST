//* Azizbek Umidjonov (ID: 20202043)
//^ functions file containing factorial and probability implementations

#include <iostream>
#include "cmath"
#include "functions.h"

double factorial(int k)
{
    if (k == 0)
        return 1;

    using namespace std;
    double res = 1;
    for (ssize_t i = 1; i <= k; i++)
    {
        res *= i;
    }
    return res;
}

double probability(int k, int n)
{
    using namespace std;
    double kfact = factorial(k);
    double power = pow(k, n);
    double nkfact = factorial(k - n);
    double div = power * nkfact;
    double res = 1 - kfact / div;

    return res;
}