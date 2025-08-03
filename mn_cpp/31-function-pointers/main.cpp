#include <iostream>
#include <vector>

void HelloWorld(int a)
{
    std::cout << "Hello world " << a << std::endl;
}

void ForEach(const std::vector<int> &values, void (*func)(int))
{
    for (int value : values)
    {
        func(value);
    }
}

void PrintValue(int value)
{
    std::cout << "Value: " << value << std::endl;
}

int main()
{
    {
        auto function = HelloWorld; // This is a pointer
        function(2);

        void (*andres)(int) = HelloWorld; // important it is a () function pointer called andres
        andres(2);

        typedef void (*hwf)(int); // Another way to alias the type;
        hwf newfunc = HelloWorld;
        newfunc(2);
    }
    {
        std::vector<int> values = {1, 2, 3, 4, 5, 6};
        ForEach(values, PrintValue);
    }
    {
        std::vector<int> values = {1, 2, 3, 4, 5, 6};
        ForEach(values, [](int value)
                { std::cout << "Value: " << value << std::endl; });
    }

    std::cin.get();
}