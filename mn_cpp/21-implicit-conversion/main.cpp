#include <iostream>

#define LOG(x) std::cout << x << std::endl;

class Entity
{
public:
    std::string m_Name;
    int m_Age;

    Entity(const std::string &name) : m_Name(name), m_Age(-1) {}

    explicit Entity(const int &age) : m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity &entity)
{
    LOG(entity.m_Name);
}

int main()
{
    Entity a("Andres"); // Expicit constructor
    Entity b(1);        // Explicit age constructor

    Entity c = std ::string("Andres"); // This is implicit conversion (String interpreted as a const char*)
    // Entity d = 22;  This cannot be done since the implicit conversion has been established

    // PrintEntity("Andres"); // This does not work since it is interpreted as const char*
    PrintEntity(std::string("Andres"));

    // PrintEntity(22); Not allowed since there is no implicit conversion
    PrintEntity(Entity(22));
    

    std::cin.get();
}