#include <iostream>
#include <tuple>

struct Point
{
    int X, Y;
    Point(int a, int b) : X(a), Y(b) {}
};

Point createPoint(int a, int b)
{
    return Point(a, b);
}

std::tuple<int, int> createTuple(int a, int b)
{
    return std::make_tuple(a, b);
}

int main()
{
    auto point = createPoint(1, 2);
    auto tuple = createTuple(1, 2);

    std::cin.get();
}