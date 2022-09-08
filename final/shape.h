#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class shape
{

public:
    virtual void print(std::ostream &) const = 0;
    virtual ~shape() {}
    virtual double area() const = 0;
    friend std::ostream &operator<<(std::ostream &, shape const &);
};

class circle : public shape
{
protected:
    virtual void print(std::ostream &) const;

public:
    double radius;
    circle(double r) : radius(r){};
    virtual double area() const;
    friend std::ostream &operator<<(std::ostream &out, shape const &sh)
    {
        sh.print(out);
        return out;
    };
    ~circle() = default;
};

class rectangle : public shape
{
protected:
    virtual void print(std::ostream &) const;

public:
    double height;
    double width;
    rectangle(double width, double height) : width(width), height(height){};
    virtual double area() const;
    friend std::ostream &operator<<(std::ostream &, shape const &);
    ~rectangle() = default;
};

shape *read_one_shape(std::istream &);

#endif