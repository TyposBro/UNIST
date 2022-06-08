#include "random-gen.h"

class random_gen
{
    virtual double between(double, double) = 0;
};

class die : public random_gen
{

    int num_sides;
    virtual int roll() const { return std::rand() % this->num_sides; }
    virtual double between(double start, double end) {};
};

class biased_die : public die
{
    int b;
};

