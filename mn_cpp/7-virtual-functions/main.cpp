#include <iostream>
#include <string>

class Entity
{
public:
    virtual std::string GetName() { return "Entity"; } // virtual tells the compiler point to the correct method
                                                       // Add overhead to the call.
};

class Player : public Entity
{
private:
    std::string m_Name;

public:
    Player(const std::string &name) : m_Name(name) {} // Constructor

    std::string GetName() override { return m_Name; } // method of the class. (override is to make this method not the one from entity)
};

void PrintName(Entity *entity)
{
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    Entity *e = new Entity();
    // std::cout << e->GetName() << std::endl;
    PrintName(e);

    Player *p = new Player("Andres");
    // std::cout << p->GetName() << std::endl;
    PrintName(p);

    Entity *entity = p; //
    // std::cout << entity->GetName() << std::endl; // This will refer to entity as an Entity object even when p is a Player
    PrintName(entity);
    std::cin.get();
}