#include <iostream>
#include <array>

template <int N>
void Print(const std::array<int, N> &data)
{
    for (auto &value : data)
    {
        std::cout << value << std::endl;
    }
}

int main()
{
    std::array<int, 5> data;
    data[0] = 2;
    data[4] = 4;

    Print<5>(data);
    // They work as static arrays just with some safety conditions and tools for iteration

    int dataOld[5];
    dataOld[0] = 0;

    std::cin.get();
}