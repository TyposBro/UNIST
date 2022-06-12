#include <cstdlib>
#include <vector>
#include <iostream>

class random_gen
{
public:
    virtual double between(double, double) = 0;
    virtual ~random_gen(){};
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
class predetermined : public random_gen<T>
{
public:
using base_t = random_gen<T>;
    T *arr;
    size_t step = 0;
    size_t n;

    predetermined(T *arr, size_t n) : arr(arr), n(n){};
    virtual double between(double, double) override;
    virtual ~predetermined(){};
};

class mix
{
};