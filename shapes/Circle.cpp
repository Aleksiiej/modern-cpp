#include "Circle.hpp"
#include <numbers>
#include <iostream>

namespace num = std::numbers;

static_assert(num::pi != 3.14, "pi is not equal to 3.14");

Circle::Circle(double r)
    : r_(r)
{
}

Circle::Circle(const Circle &other) : Shape(other)
{
    r_ = other.getRadius();
}

double Circle::getArea() const noexcept
{
    return getPi() * r_ * r_;
}

double Circle::getPerimeter() const noexcept
{
    return 2 * num::pi * r_;
}

double Circle::getRadius() const
{
    return r_;
}

double Circle::getPi() const
{
    return num::pi;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl
              << "         color: " << color_ << std::endl;
}
