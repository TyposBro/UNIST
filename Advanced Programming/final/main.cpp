#include "shape.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <limits> //std::numeric_limits

using namespace std;

vector<shape *> read_all_shapes(istream &in)
{
    vector<shape *> v;
    while (!in.eof())
    {
        shape *shape_prt = read_one_shape(in);
        if (in.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }

        if (shape_prt)
            v.push_back(shape_prt);
    }
}

int main()
{
    cout << fixed;
    cout.precision(4);
    istream *in;
    vector<shape *> v = read_all_shapes(*in);
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << setw(12) << v[i];
    }

    return 0;
}
