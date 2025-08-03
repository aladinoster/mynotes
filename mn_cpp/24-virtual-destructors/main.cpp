#include <iostream>

class Base
{
public:
    Base() { std::cout << "Constructed" << std::endl; }
    virtual ~Base() { std::cout << "Destructed" << std::endl; } // Ensures that the DerivedBase destructor is called
};

class DerivedBase : public Base
{
public:
    DerivedBase()
    {
        m_Array = new int[5];
        std::cout << "Derived Constructed" << std::endl;
    }
    ~DerivedBase()
    {
        delete m_Array;
        std::cout << "Derived Destructed" << std::endl;
    }

private:
    int *m_Array;
};

int main(int argc, char const *argv[])
{
    Base *base = new Base();
    delete base;

    std::cout << "------------------\n";

    DerivedBase *derived = new DerivedBase();
    delete derived;

    std::cout << "------------------\n";
    Base *poly = new DerivedBase(); // Polymorphism
    delete poly;

    std::cin.get();
}
