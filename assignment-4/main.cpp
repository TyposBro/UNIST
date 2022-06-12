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
    int sides;
    int biased_side;
    double start;
    double end;
    vector<random_gen *> v;

    while (c != 0)
    {
        cout << "(0) Quit" << endl;
        cout << "(1) Add a die" << endl;
        cout << "(2) Add a that cheats" << endl;
        cout << "(3) Add a die that cycles 0, 2, 4, 1, 3, 5, ..." << endl;
        cout << "(4) Add a sequence of fractions 1, 1/2, 1/3, 1/4, 1/5, 1/6, 1/7, 1/8, 1, 1/2, ..." << endl;
        if (v.size() > 1)
            cout << "(5) Add a mixture of the last two generators added" << endl;

        cout << "(6) Generate random numbers" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        if (c == 1)
        {
            cout << "How many sides? ";
            cin >> sides;
            die *d = new die(sides);
            v.push_back(d);
        }
        if (c == 2)
        {

            cout << "How many sides? ";
            cin >> sides;
            cout << "Which side should be chosen less often (0-"
                 << sides - 1 << ")? ";
            cin >> biased_side;
            biased_die *biased = new biased_die(sides, biased_side);
            v.push_back(biased);
        }
        if (c == 3)
        {
            int arr[6] = {0, 2, 4, 1, 3, 5};
            predetermined<int> *cycles = new predetermined<int>(arr, 6);
            v.push_back(cycles);
        }

        if (c == 4)
        {
            double arr[8] = {(double)1, (double)1 / 2, (double)1 / 3, (double)1 / 4, (double)1 / 5, (double)1 / 6, (double)1 / 7, (double)1 / 8};
            predetermined<double> *factions = new predetermined<double>(arr, 8);
            v.push_back(factions);
        }
        if (c == 5)
        {
            random_gen *first = v[v.size() - 1];
            random_gen *second = v[v.size() - 2];
            //* init
            mix<random_gen, random_gen> *m = new mix<random_gen, random_gen>(first, second);
            v.push_back(m);
        }

        if (c == 6)
        {
            cout << "Between what and what? ";
            scanf("%lf %lf", &start, &end);
            for (size_t i = 0; i < v.size(); i++)
                cout << v[i]->between(start, end) << " ";
            cout << endl;
        }
    }

    for (size_t i = 0; i < v.size(); i++)
        delete v[i];

    return 0;
}
