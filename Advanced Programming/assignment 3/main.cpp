#include <iostream>
#include <bits/stdc++.h>

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

    string space_delimiter = " ";
    vector<string> words{};
    string arr1[MAX_LEN];

    size_t pos = 0;
    size_t index1;
    while ((pos = str1.find(space_delimiter)) != string::npos)
    {
        arr1[index1] = str1.substr(0, pos);
        str1.erase(0, pos + space_delimiter.length());
        index1++;
    }

    for (size_t i = 0; i < index1; i++)
    {
        cout << arr1[i] << endl;
    }

    return 0;
}
