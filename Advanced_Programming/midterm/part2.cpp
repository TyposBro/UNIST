#include <iostream>
#include <cstring>
using namespace std;
char sum_digits(char *s)
{
    if (s[0] == '\0')
        return '0';
    else if (s[1] == '\0')
        return s[0];
    else if (s[0] == '0')
        return sum_digits(s + 1);
    int first = s[0] - '0';
    int second = s[1] - '0';
    int result = first + second;
    first = result / 10;
    second = result % 10;
    s[0] = first + '0';
    s[1] = second + '0';
    return sum_digits(s);
}

int main()
{
    char[100] s = '123';
    cout << sum_digits(s);
    return 0;
}
