#include "utils.h"

int main()
{
    using namespace std;

    rna_base rna1[1000], rna2[1000];

    size_t len1 = get_input(rna1);
    size_t len2 = get_input(rna2);
    if (len1 == 0 or len2 == 0)
    {
        cout << "Bad input" << endl;
        return 1;
    }

    cout << "Best Score: " << score_without_realigning(rna1, len1, rna2, len2) << endl;
    return 0;
}