#include <iostream>
#include <string>

class Entity
{
public:
    std::string m_Value;
    Entity() : m_Value("Unknown") {}
    Entity(const std::string &name) : m_Value(name) {}
    void Print()
    {
        std::cout << m_Value << std::endl;
    }
};

int main()
{
    Entity *e;
    {
        Entity ent = Entity();                 // Destroyed after getting out of the scope
        Entity *entity = new Entity("Cherno"); // Heap memory allocation
        e = entity;                            // Assigns pointer to pointer
        e->Print();
    }
    std::cin.get();
    delete e; // Manually deallocating memory;
}