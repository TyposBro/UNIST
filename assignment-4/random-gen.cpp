#include "random-gen.h"

double die::between(double start, double end)
{
    //* TODO: Die Betwwen
}

int biased_die::roll() const
{
    size_t count = 0;
    int result = std::rand() % this->num_sides;
    if (result == b)
        return std::rand() % this->num_sides;
    return result;
};
double biased_die::between(double start, double end){};