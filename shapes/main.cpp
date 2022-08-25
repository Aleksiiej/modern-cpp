#include <algorithm>
#include <chrono>
#include <initializer_list>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea = [](auto first, auto second)
{if (first == nullptr || second == nullptr)
    {

        return false;
    }
    return (first->getArea() < second->getArea()); };

auto perimeterBiggerThan20 = [](auto s)
{
    if (s)
    {
        return (s->getPerimeter() > 20);
    }
    return false;
};

auto areaLessThanX = [x = 10](auto s)
{ if (s)
    {
        return (s->getArea() < x);
    }
    return false; };

auto areaLessThan10(shared_ptr<Shape> s)
{
    if (s)
    {
        return (s->getArea() < 10);
    }
    return false;
}

void printCollectionElements(const Collection &collection)
{
    for (const auto &el : collection)
    {
        if (el)
            el->print();
    }
}

void printAreas(const Collection &collection)
{
    for (const auto &el : collection)
    {
        if (el)
            cout << el->getArea() << std::endl;
    }
}

void findFirstShapeMatchingPredicate(const Collection &collection,
                                     std::function<bool(shared_ptr<Shape> s)> predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

// constexpr int fib(int number)
// {
//     if (number == 0)
//     {
//         return 0;
//     }
//     else if (number == 1)
//     {
//         return 1;
//     }
//     else
//         return (fib(number - 1) + fib(number - 2));
// }
// constexpr int result = fib(45);

int main()
{
    // auto start = std::chrono::steady_clock::now();
    // int result = fib(45);
    // auto end = std::chrono::steady_clock::now();
    // std::cout << "Fibonacci number : " << result << std::endl;
    // std::cout << "Time(miliseconds): " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;

    Collection shapes = {
        make_shared<Circle>(2.0),
        make_shared<Circle>(3.0),
        nullptr,
        make_shared<Circle>(4.0),
        make_shared<Rectangle>(10.0, 5.0),
        make_shared<Square>(3.0),
        make_shared<Circle>(4.0),
    };
    shapes.push_back(make_shared<Circle>(Color::RED));
    printCollectionElements(shapes);
    Circle c{Color::WHITE};
    cout << c.getPi() << endl;

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than X");

    // std::cout << alignof(Circle) << std::endl;

    // std::map<shared_ptr<Shape>, double> perimeters;
    // for (const auto &el : shapes)
    // {
    //     if (el)
    //     {
    //         perimeters.emplace(el, el->getPerimeter());
    //     }
    // }

    // for (auto&& [shape, perimeter] : perimeters)
    // {
    //     shape->print();
    //     std::cout << "perimeter is: " << perimeter << endl;
    // }

    return 0;
}
