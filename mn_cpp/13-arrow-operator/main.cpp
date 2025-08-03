#include <iostream>
#include <string>

class Entity
{
public:
    int x;
    void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr
{
private:
    Entity *mObject;

public:
    ScopedPtr(Entity *entity) : mObject(entity) {}

    ~ScopedPtr()
    {
        delete mObject;
    }

    const Entity *operator->() const
    {
        return mObject;
    }
};

struct Vector3
{
    float x, y, z;
};

int main()
{
    Entity e;
    e.Print();

    // Pointer
    Entity *ptr = &e;
    ptr->Print();
    (*ptr).Print(); // Equivalent to -> (This is called dereferencing)
    //Attribute access
    ptr->x = 2;

    ScopedPtr entity = new Entity();
    entity->Print();

    // A smart way to access offsets in memory
    long int offset_x = (long int)&((Vector3 *)nullptr)->x; // long int because we are on 64 bit
    
    long int offset_y = (long int)&((Vector3 *)nullptr)->y;
    long int offset_z = (long int)&((Vector3 *)nullptr)->z;
    std::cout << offset_x << " " << offset_y << " " << offset_z << std::endl;

    std::cin.get();
}