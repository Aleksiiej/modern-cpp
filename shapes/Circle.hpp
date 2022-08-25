#pragma once

#include "Shape.hpp"

class alignas(128) Circle final : public Shape
{
public:
    using Shape::Shape;
    Circle() = delete;
    Circle(double r);
    Circle(const Circle &other);

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getRadius() const;
    /*[[deprecated("please use pi from <numbers>")]]*/
    double getPi() const;
    void print() const override;

private:
    double r_{1.0};
};
