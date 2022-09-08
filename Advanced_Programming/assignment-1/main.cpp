//* Azizbek Umidjonov (ID: 20202043)
//^ main driver file containing functions for getting input from a user and printing values
#include <iostream>
#include "functions.h"
#include <iomanip>

int get_input()
{
    using namespace std;
    cout << "Enter a number: ";
    int k;
    cin >> k;

    if (!cin or k <= 0)
        exit(1);

    return k;
}

void print(int k)
{
    using namespace std;

    cout << fixed;
    cout.precision(7);

    for (ssize_t n = 1; n <= k; n++)
    {
        double res = probability(k, n);
        cout << setw(2) << right << n << " " << setw(10) << right << res * 100 << endl;
    }
}

int main()
{
    using namespace std;
    int k;

    while (true)
    {
        k = get_input();
        print(k);
    }

    return 0;
}
