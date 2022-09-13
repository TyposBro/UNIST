//* Azizbek Umidjonov (ID: 20202043)
//^ unit tests file containing CHECK function to compare any two double values and 9 testcases

#include <iostream>
#include <limits>
#include "functions.h"
#include <algorithm>
int fact = 10e8;

int CHECK(double val, double exp, std::string func)
{
    using namespace std;
    if (val == exp || abs(val - exp) < abs(min(val, exp)) * numeric_limits<double>::epsilon() * fact)
        return 0;
    else
    {
        cout << func << " function was expecting: " << exp << " but found: " << val << endl;
        return 1;
    }
}

int main()
{
    using namespace std;
    cout << fixed;
    cout.precision(7);

    int fail = 0;
    //* Factorial
    fail += CHECK(factorial(0), 1, "Factorial");
    fail += CHECK(factorial(3), 6, "Factorial");
    fail += CHECK(factorial(4), 24, "Factorial");
    fail += CHECK(factorial(12), 479001600, "Factorial");
    fail += CHECK(factorial(14), 87178291200, "Factorial");

    //* Probability
    fail += CHECK(probability(12, 1), 0.0000000, "Probability");
    fail += CHECK(probability(12, 4), 0.427083333, "Probability");
    fail += CHECK(probability(12, 8), 0.953583140, "Probability");
    fail += CHECK(probability(6, 2), 0.166666667, "Probability");
    fail += CHECK(probability(13, 13), 0.999979440, "Probability");
    if (fail == 0)
        cout << "All tests passed" << endl;
    else
        cout << fail << " tests failed in Probability function" << endl;
}