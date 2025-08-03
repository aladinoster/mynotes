#include <iostream>
#include <cstring>

class Entity
{
private:
    std::string m_Name;
    mutable int m_DebugCount = 0;

public:
    const std::string &GetName() const
    {
        m_DebugCount++; //This can be done because of the mutable keyword
        return m_Name;
    } // We promise we won't modify the class
};

int main()
{
    const Entity e; // If we use this some methods needs to be const otherwise they cannot be called.
    e.GetName();    // Example

    int x = 8;

    auto f = [=]() mutable // Passing by value
    {
        x++;
        std::cout << x << std::endl;
    };

    f();

    std::cin.get();
}