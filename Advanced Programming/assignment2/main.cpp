#include <iostream>
#include <cmath>
#include <limits> //std::numeric_limits
#include "array.h"
#include <iomanip>

void print_daily_highs(double *values, size_t length)
{
    using namespace std;
    cout << "Daily highs" << endl
         << "==========="
         << endl;
    for (size_t i = 0; i < length; i++)
    {

        cout << setw(12) << right << values[i] << endl;
    }
    cout << endl;
}

void daily_highs(double *values, size_t n)
{
    size_t blocks = (size_t)ceil((double)n / 24);

    double *daily_highs_values = new double[blocks];

    for (size_t i = 0; i < blocks; i++)
    {
        size_t count = 24;
        if (i + 1 == blocks)
        {
            count = n - 24 * i;
        }
        double *mini = new double[count];
        for (size_t j = 0; j < count; j++)
        {
            mini[j] = values[i * 24 + j];
        }
        daily_highs_values[i] = *maximum_value(mini, count);
        delete[] mini;
    }
    print_daily_highs(daily_highs_values, blocks);
    delete[] daily_highs_values;
}

void get_input(double *values, size_t *n)
{
    using namespace std;
    while (cin && !cin.eof() && *n < 1000)
    {

        cin >> values[*n];
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            values[*n] = NAN;
        }
        if (cin.eof())
        {
            (*n)--;
        }

        if (cin)
            (*n)++;
    }
}

void sliding_window(double *values, size_t n)
{
    using namespace std;
    cout << "Sliding window 24-hour averages" << endl;
    cout << "===============================" << endl;
    for (size_t i = 0; i < n; i++)
    {
        size_t start = i > 12 ? i - 12 : 0;
        size_t end = i + 12 < n ? i + 12 : n;

        cout << setw(12) << right << values[i];
        cout << setw(12) << right << mean(&values[start], end - start) << endl;
    }
    cout << endl;
}

// void foo_bar(double *values, size_t n)
// {
//     using namespace std;
//     size_t foo = 0;
//     for (size_t i = 0; i < n; i++)
//     {
//         if (isnan(values[i]))

//             foo++;
//     }
//     cout << "foo: " << foo << endl;
// }

void general_mean(double *values, size_t n)
{
    using namespace std;
    cout << "Overall mean: " << mean(values, n) << endl;

    double *highest = maximum_value(values, n);
    *highest = NAN;
    cout << "Mean after removing the largest value: " << mean(values, n) << endl;

    double *second_highest = maximum_value(values, n);
    *second_highest = NAN;
    cout << "Mean after removing the 2 largest values: " << mean(values, n) << endl;
}

int main()
{
    using namespace std;

    double values[1000];
    size_t n = 0;
    cout << fixed;
    cout.precision(3);
    get_input(values, &n);
    daily_highs(values, n);
    sliding_window(values, n);
    general_mean(values, n);
    return 0;
}
