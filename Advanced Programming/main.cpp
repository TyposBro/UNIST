#include <iostream>
#include <cstring>

using namespace std;

char sum_digits(char *s)
{
    /* write this function!! */
    if (s == NULL)
    {
        return 0;
    }

    return s[0] + sum_digits(s + 1);
}

int main()
{
#define TEST(x, v)                                                                                                                                                                \
    {                                                                                                                                                                             \
        char array[] = x;                                                                                                                                                         \
        if (sum_digits(array) == v)                                                                                                                                               \
            cout << "line " << __LINE__ << " (" << x << ") was correct!! (" << v << ")" << endl;                                                                                  \
        else                                                                                                                                                                      \
            cerr << "line " << __LINE__ << " (" << x << ") IS INCORRECT!!! Expected " << v << ", but got " << sum_digits(array) << " (" << (int)sum_digits(array) << ")" << endl; \
    }
    TEST("0", '0');
    TEST("1", '1');
    TEST("2", '2');
    TEST("3", '3');
    TEST("10", '1');
    TEST("01", '1');
    TEST("18", '9');
    TEST("19", '1');
    TEST("47", '2');
    TEST("99", '9');
    TEST("100", '1');
    TEST("101", '2');
    TEST("110", '2');
    TEST("111", '3');
    TEST("1293847912874918237491823749812374", '5');
    TEST("3298723876123476129847912837487132648761238741", '5');
    TEST("1213262531023492384283400", '6');
    TEST("99999999999999999999999999999999999999999999999999999999999999999999999", '9');
    return 0;
}
