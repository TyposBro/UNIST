#include "random-gen.h"
#include <random>

double die::between(double start, double end)
{
    //* TODO: Die Betwwen
    //! Generate array of uniformly distributed numbers within a range
    double *arr = new double(num_sides);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> urd(start, end);

    for (int n = 0; n < num_sides; ++n)
        arr[n] = urd(gen);

    return arr[roll()];
}

int biased_die::roll() const
{
    int result = std::rand() % this->num_sides;
    if (result == b)
        return std::rand() % this->num_sides;
    return result;
};
double biased_die::between(double start, double end)
{

    //* TODO: Biased Die Betwwen
    //! Generate array of uniformly distributed numbers within a range
    double *arr = new double(num_sides);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> urd(start, end);

    for (int n = 0; n < num_sides; ++n)
        arr[n] = urd(gen);

    return arr[roll()];
};