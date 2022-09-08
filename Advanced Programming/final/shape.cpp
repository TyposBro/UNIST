#include "shape.h"
#include <math.h>
using namespace std;

shape *read_one_shape(std::istream &in)
{
    char c;
    double x1, x2;
    in.get(c);
    switch (c)
    {
    case 'C':
    case 'c':
        in >> x1;
        return new circle(x1);
    case 'R':
    case 'r':
        in >> x1 >> x2;
        return new rectangle(x1, x2);
    default:
        return nullptr;
    }
}

double circle::area() const
{
    return M_PI * this->radius * this->radius;
};
double rectangle::area() const
{
    return M_PI * this->width * this->height;
};

void circle::print(std::ostream &out) const
{
    out << "Circle(" << this->radius << ")";
}
void rectangle::print(std::ostream &out) const
{
    out << "Rectangle(" << this->width << "," << this->height << ")";
}
