// Azizbek Umidjonov (ID: 20202043)
// Midterm Assignment 1

#include <iostream>
#include <cmath>
#include <limits>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    double values[20];
    size_t n = 0;
    size_t correctVals = 0;
    double sum = 0;
    while (cin && !cin.eof() && n < 20)
    {

        cin >> values[n];
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            values[n] = NAN;
            n--;
        }
        if (cin.eof())
            break;

        if (cin)
            (n)++;
        correctVals++;
    }

    for (size_t i = 0; i < n; i++)
        sum += values[i];

    double mean = sum / n;

    cout << fixed;
    cout.precision(1);
    cout << correctVals << " lines read in" << endl;
    cout << n << " valid lines read in" << endl;
    cout << "mean temperature is " << mean << endl;
    cout.precision(3);
    cout << "temperatures colder than the mean" << endl;
    for (size_t i = 0; i < n; i++)
    {
        if (mean > values[i])
            cout << setw(10) << values[i] << endl;
    }

    return 0;
}