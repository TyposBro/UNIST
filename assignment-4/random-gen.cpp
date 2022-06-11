#include "random-gen.h"
#include <random>

double die::between(double start, double end)
{
    //! Generate array of uniformly distributed numbers within a range
    double *arr = new double(num_sides);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> urd(start, end);

    for (int n = 0; n < num_sides; ++n)
        arr[n] = urd(gen);

    double ans = arr[roll()];
    delete[] arr;
    return ans;
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
    //! Generate array of uniformly distributed numbers within a range
    double *arr = new double[num_sides];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> urd(start, end);

    for (int n = 0; n < num_sides; ++n)
        arr[n] = urd(gen);

    double ans = arr[roll()];
    delete[] arr;
    return ans;
};

template <class T>
double predetermined<T>::between(double a, double b)
{
    //             (b - a)(x - min)
    //     f(x) = ------------------ + a = 4*1/5-2
    //                  max -min
    //
    // max = 10 / min = 5
    // a = -2 / b = 2
    // x = 6

    double min_v = arr[0];
    double max_v = arr[n - 1];

    double ans = (b - a) * (arr[step] - min_v) / (max_v - min_v) + a;
    step++;
    return ans;
}