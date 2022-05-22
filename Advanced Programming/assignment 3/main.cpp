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

void get_input(std::string *arr, size_t *len)
{
    using namespace std;
    regex r("[0,1,2,3, A,C,U,G, a,c,u,g]");
    string str;

    getline(cin, str);
    str += " ";

    string space_delimiter = " ";
    size_t pos = 0;

    while ((pos = str.find(space_delimiter)) != string::npos)
    {
        if (regex_match(str.substr(0, pos), r))
        {
            arr[*len] = str.substr(0, pos);
            (*len)++;
        }

        str.erase(0, pos + space_delimiter.length());
    }
}

int main()
{
    using namespace std;
    string arr1[1000];
    size_t len1 = 0;
    string arr2[1000];
    size_t len2 = 0;
    get_input(arr1, &len1);
    get_input(arr2, &len2);

    cout << "1st: ";
    for (size_t i = 0; i < len1; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << "2nd: ";
    for (size_t i = 0; i < len2; i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}
