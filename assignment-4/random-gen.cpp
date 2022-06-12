#include "random-gen.h"
#include <random>

double die::between(double a, double b)
{
    //! Generate array of uniformly distributed numbers within a range
    double max_v = num_sides;
    double min_v = 0;
    double ans = (b - a) * (roll() - min_v) / (max_v - min_v) + a;
    return ans;
}

int biased_die::roll() const
{
    int result = std::rand() % this->num_sides;
    if (result == b)
        return std::rand() % this->num_sides;
    return result;
};
double biased_die::between(double a, double b)
{
    //! Generate array of uniformly distributed numbers within a range
    double max_v = num_sides;
    double min_v = 0;
    double ans = (b - a) * (roll() - min_v) / (max_v - min_v) + a;
    return ans;
};

template <class T>
double predetermined<T>::between(double a, double b) override
{
    //             (b - a)(x - min)
    //     f(x) = ------------------ + a = 4*1/5-2
    //                  max -min
    //
    //     max = 10 / min = 5
    //     a = -2 / b = 2
    //     x = 6

    double min_v = arr[0];
    double max_v = arr[n - 1];

    double ans = (b - a) * (arr[step] - min_v) / (max_v - min_v) + a;
    step++;
    return ans;
}