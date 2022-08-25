#pragma once
#include <iostream>

enum class Color : unsigned char
{
    WHITE = 0x01,
    RED = 0x02,
    BLUE = 0x03,
};

std::ostream &operator<<(std::ostream &os, Color c);

class Shape
{
public:
    Shape(Color c) : color_(c) {}
    Shape() {}
    Shape(Shape const &sh) : color_(sh.color_) {}
    virtual ~Shape() = default;

    virtual double getArea() const noexcept = 0;
    virtual double getPerimeter() const noexcept = 0;
    virtual void print() const;

protected:
    Color color_{Color::WHITE};
};
