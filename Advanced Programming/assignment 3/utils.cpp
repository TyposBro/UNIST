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

    for (size_t i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;

    return len;
}