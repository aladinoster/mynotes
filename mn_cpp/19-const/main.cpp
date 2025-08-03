#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

class Entity
{
private:
    int m_X, m_Y;
    int *m_Z, *m_W;
    mutable int var;

public:
    const int *const GetZ() const
    {
        return m_Z; // Return a constant pointer with constant value.
    }
    int GetX()
    {
        return m_X;
    }
    int GetX() const
    {
        // m_X = 2; This is not possible
        var = 2;    // This is legal inside a const method because var is mutable.
        return m_X; // This method does not modify the class member variables
    }
    void SetX()
    {
        m_X = 2; // This cannot be const ( A setter is not const)
    }
};

void PrintEntity(const Entity &e)
{
    // e= Entity(); This is not legal since e is a constant reference

    LOG(e.GetX()); // since GetX is const it promises not to modify the class and one can use e without any problem
    // This uses the const method..

    // To remember if const in arguments -> const in methods!
}

int main()
{
    const int MAX_AGE = 90;

    int *const a = new int; // int pointer constant ( you cannot modify the address)

    *a = 2; // change content of the pointer.

    // change the memory adress of the pointer.

    // a = (int *)&MAX_AGE; we ask take the addresss of MAX_AGE cast as a pointer of type int an assign it to a not possible since the pointer is constant (Does not work)

    const int *b = new int; // Const int pointer (you cannot modify the content)

    b = (int *)&MAX_AGE; // we ask take the address of MAX_AGE cast as a pointer  it works because const int may be considered as constant.

    // *b = 2; This cannot be done (Does not work)

    const int *const c = new int; // you can not change the address nor the content.

    std::cin.get();
}