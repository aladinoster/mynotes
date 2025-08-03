#include <iostream>

#define LOG(X) std::cout << X << std::endl;

int main()
{
    for (int i = 0; i < 6; i++)
    {
        if (i == 3)
            continue;
        LOG(i);
    }
    std::cin.get();
}