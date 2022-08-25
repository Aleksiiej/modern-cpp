#include "Shape.hpp"

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}

std::ostream &operator<<(std::ostream &os, Color c)
{
    if (c == Color::WHITE)
    {
        os << "White";
    }
    else if (c == Color::RED)
    {
        os << "Red";
    }
    else if (c == Color::BLUE)
    {
        os << "Blue";
    }
    return os;
}
