//* Azizbek Umidjonov (ID: 20202043)
//^ Advanced Programming Assignment 03
//! main file to manage code execusion

#include "utils.h"

int main()
{
    using namespace std;

    rna_base rna1[MAX_LEN], rna2[MAX_LEN];

    size_t len1 = get_input(rna1);
    size_t len2 = get_input(rna2);
    if (len1 == 0 or len2 == 0)
    {
        cout << "Bad input" << endl;
        return 1;
    }
    long shift = 0;

    cout << "Best score: " << best_alignment(rna1, len1, rna2, len2, shift) << endl;

    cout << "Best alignment: " << shift << endl;
    print(rna1, len1, rna2, len2, shift);
    return 0;
}