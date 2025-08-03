#include <iostream>

#define LOG(x) std::cout << x << std::endl

void IncrementPointer(int *ptr)
{
    (*ptr)++;
}

void Increment(int &value)
{
    value++;
}

int main()
{
    int a = 5;
    Increment(a);
    LOG(a);
    IncrementPointer(&a);
    LOG(a);
    std::cin.get();
}