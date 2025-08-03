#include <iostream>

template <typename T, int N> // templates are allocated at run time so this provides flexibility. (Also risky!)
class Array
{
private:
    T Array[N];

public:
    int getSize() const { return N; }
};

int main(int argc, char const *argv[])
{
    /* code */
    Array<int, 5> array;
    std::cout << array.getSize() << std::endl;
    std::cin.get();
    return 0;
}
