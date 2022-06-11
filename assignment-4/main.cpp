#include "random-gen.h"

int main(int argc, char **argv)
{

    if (argc == 2)
        srand(strtoul(argv[1], nullptr, 0));
    else
        srand(time(nullptr));

    //* My Code starts here
    //* ###################
    using namespace std;
    unsigned int c = 123;
    unsigned int sides;
    unsigned int n;
    double start;
    double end;
    cout << c << endl;
    while (c != 0)
    {
        cout << "(0) Quit" << endl;
        cout << "(1) Add a die" << endl;
        cout << "(2) Add a that cheats" << endl;
        cout << "(3) Add a die that cycles 0, 2, 4, 1, 3, 5, ..." << endl;
        cout << "(4) Add a sequence of fractions 1, 1/2, 1/3, 1/4, 1/5, 1/6, 1/7, 1/8, 1, 1/2, ..." << endl;
        cout << "(5) Add a mixture of the last two generators added" << endl;
        cout << "(6) Generate random numbers" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        if (c == 1)
        {
            cout << "How many sides? ";
            int sides;
            cin >> sides;
            die d(sides);
        }
        if (c == 2)
        {
            cout << "How many sides? ";
            cin >> sides;
            cout << "Which side should be chosen less often (0-"
                 << sides - 1 << ")? ";
            cin >> n;
        }
        if (c == 6)
        {
            cout << "Between what and what? ";
            cin >> start;
            cin >> end;
        }
    }

    return 0;
}
