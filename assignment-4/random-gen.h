#include <cstdlib>
#include <vector>
#include <iostream>

class random_gen
{
public:
    random_gen() = default;
    virtual double between(double, double) = 0;
    virtual ~random_gen() = default;
};

class die : public random_gen
{
public:
    int num_sides;
    die(int sides) : num_sides(sides){};
    virtual int roll() const { return std::rand() % this->num_sides; }
    virtual double between(double, double);
    virtual ~die(){};
};

class biased_die : public die
{

public:
    int b;
    biased_die(int sides, int biased) : die(sides), b(biased){};
    virtual int roll() const;
    virtual double between(double, double);
    virtual ~biased_die(){};
};

template <class T>
class predetermined : public random_gen
{
public:
    T *arr;
    size_t step = 0;
    size_t n;

    predetermined(T *array, size_t n)
    {
        arr = new T[n];
        for (size_t i = 0; i < n; i++)
            this->arr[i] = array[i];
        this->n = n;
    };
    virtual double between(double a, double b)
    {
        //             (b - a)(x - min)
        //     f(x) = ------------------ + a
        //                  max -min
        //
        //     max = 5 / min = 0
        //     a = 0 / b = 5
        //     x = 6
        double min_v = arr[0];
        double max_v = arr[n - 1];

        for (size_t i = 0; i < n; i++)
        {
            if (min_v > arr[i])
                min_v = arr[i];

            if (max_v < arr[i])
                max_v = arr[i];
        }

        double ans = (b - a) * (arr[step] - min_v) / (max_v - min_v) + a;

        if (step < n - 1)
        {
            step++;
        }
        else
        {
            step = 0;
        }

        return ans;
    }
    virtual ~predetermined()
    {
        delete[] arr;
    };
};

template <class T, class U>
class mix : public random_gen
{
public:
    T *first;
    U *second;
    mix(T *f, U *s) : first(f), second(s){};
    virtual double between(double start, double end)
    {
        double mid = (end - start) / 2;
        double ans = first->between(start, mid) + second->between(start, mid);

        return ans;
    }
    virtual ~mix() = default;
};