#include <iostream>
#include <bits/stdc++.h>
#include <regex>

#define MAX_LEN 1000
enum DNA
{
    A,
    C,
    U,
    G
};

int main()
{
    using namespace std;
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    string bigStr = str1.size() > str2.size() ? str1 : str2;
    string smallStr = str1.size() < str2.size() ? str1 : str2;
    size_t bigSize = bigStr.size();
    size_t smallSize = smallStr.size();

    string whiteSpace(smallSize - 2, ' ');
    bigStr = whiteSpace + bigStr + whiteSpace;

    for (size_t i = 0; i < bigSize + smallSize - 1; i += 2)
    {
        
    }

    return 0;
}
