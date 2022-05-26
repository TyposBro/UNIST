#include "utils.h"

size_t get_input(rna_base *arr)
{
    using namespace std;
    size_t len = 0;
    string text;

    do
    {
        cin >> text;
        if (len >= MAX_LEN)
            return 0;
        else if (text == " " || text == "\n")
            continue;
        else if (text == "A")
            arr[len] = A;

        else if (text == "C")
            arr[len] = C;

        else if (text == "U")
            arr[len] = U;

        else if (text == "G")
            arr[len] = G;

        len++;
    } while (text == "A" || text == "C" || text == "U" || text == "G");
    len--;

    // for (size_t i = 0; i < len; i++)
    //     cout << arr[i] << " ";
    // cout << endl;

    return len;
}
std::string convert(rna_base base)
{
    switch (base)
    {
    case A:
        return "A";
    case C:
        return "C";
    case U:
        return "U";
    case G:
        return "G";
    }
    return "Bad input";
}
void print(rna_base const *rna1, size_t len1, rna_base const *rna2, size_t len2, long &shift)
{
    using namespace std;
    if (shift < 0)
    {
        for (size_t i = 0; i < (size_t)abs(shift); i++)
        {
            cout << "  ";
        }
        for (size_t i = 0; i < len1; i++)
            cout << convert(rna1[i]) << " ";
        cout << endl;
        for (size_t i = 0; i < len2; i++)
            cout << convert(rna2[i]) << " ";
        cout << endl;
    }
    else if (shift > 0)
    {
        for (size_t i = 0; i < len1; i++)
            cout << convert(rna1[i]) << " ";
        cout << endl;
        for (size_t i = 0; i < (size_t)abs(shift); i++)
        {
            cout << "  ";
        }
        for (size_t i = 0; i < len2; i++)
            cout << convert(rna2[i]) << " ";
        cout << endl;
    }
    else
    {
        for (size_t i = 0; i < len1; i++)
            cout << convert(rna1[i]) << " ";
        cout << endl;
        for (size_t i = 0; i < len2; i++)
            cout << convert(rna2[i]) << " ";
        cout << endl;
    }
}