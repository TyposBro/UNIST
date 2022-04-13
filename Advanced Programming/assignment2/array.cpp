#include "array.h"
#include <cmath>
#include <limits> //std::numeric_limits
#include <iostream>

double mean(double const *values, size_t n)
{

        size_t count = 0;
    double res = 0;
    for (size_t i = 0; i < n; i++)
    {
        using namespace std;
        if (isnan(values[i]))
            continue;

        res += values[i];
        count++;
    }
    if (count == 0)
        return NAN;

    // res = ;
    return res / count;
};
double *maximum_value(double *values, size_t n)
{
    using namespace std;

    double max = -100000;
    size_t track = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (isnan(values[i]))
        {
            i++;
            continue;
        }
        if (max < values[i])
        {
            max = values[i];
            track = i;
        }

        // i++;
    }

    return &values[track];
};
