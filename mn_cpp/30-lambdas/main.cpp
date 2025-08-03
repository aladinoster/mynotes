#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void ForEach(const std::vector<int> &values, const std::function<void(int)> &func)
{
    for (int value : values)
    {
        func(value);
    }
}

int FindIf(const std::vector<int> &values)
{
    for (int value : values)
    {
        if (value > 3)
        {
            return value;
        }
    }
    return 0;
}

int main()
{
    {
        std::vector<int> values = {1, 2, 3, 4, 5, 6};
        auto iterator = std::find_if(values.begin(), values.end(), [](int value)
                                     { return value > 3; });

        std::cout << *iterator << std::endl;

        std::cout << FindIf(values) << std::endl; //Equivalent mm not exactly but kind of

        auto lambda = [](int value)
        { std::cout << "Value: " << value << std::endl; };

        // [] How do we capture [=] by value , [& byref]
        int a = 5;
        auto lambdacap = [&a](int value)
        { std::cout << "Value: " << value << a << std::endl; };

        ForEach(values, lambda);
        ForEach(values, lambdacap);
    }

    std::cin.get();
}