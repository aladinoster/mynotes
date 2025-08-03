#include <iostream>

#define LOG(x) std::cout << x << std::endl;

class Base
{
public:
    Base() {}
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    Derived() {}
    ~Derived() {}
};

class Anotherclass : public Base
{
public:
    Anotherclass() {}
    ~Anotherclass() {}
};

int main(int argc, char const *argv[])
{
    double value = 5.25;
    double a = value + 5.3;
    double c = (int)(value + 5.3); // 10

    double d = (int)value + 5.3; // 10.3

    double s = static_cast<int>(value) + 5.3; // 10.3

    LOG(a);
    LOG(c);
    LOG(d);
    LOG(s);

    Derived *derived = new Derived();
    Base *base = derived;

    Anotherclass *ac = dynamic_cast<Anotherclass *>(base);
    std::cin.get();
    return 0;
}
