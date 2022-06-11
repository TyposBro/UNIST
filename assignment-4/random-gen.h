#include <cstdlib>
#include <vector>
#include <iostream>

class random_gen
{
public:
    virtual double between(double, double) = 0;
};

class die : public random_gen
{
public:
    int num_sides;
    die(int sides) : num_sides(sides){};
    virtual int roll() const { return std::rand() % this->num_sides; }
    virtual double between(double, double);
};

class biased_die : public random_gen, public die
{

public:
    int b;
    biased_die(int sides, int biased) : die(sides), b(biased){};
    virtual int roll() const;
    virtual double between(double, double);
};

template <class T>
class predetermined
{
};

class mix
{
};