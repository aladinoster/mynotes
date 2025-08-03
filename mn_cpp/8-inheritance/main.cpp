#include <iostream>
#include <string>

class Entity
{
public:
    float X, Y;

    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }
};

class Player : public Entity
{
public:
    std::string Name;

    Player(const std::string &name) : Name(name) {}
    void printName()
    {
        std::cout << Name << std::endl;
    }
};

int main()
{
    Player *player = new Player("Andres");

    std::cout << "Size of Player is: " << sizeof(Player) << std::endl;
    std::cout << "Size of Entity is: " << sizeof(Entity) << std::endl;

    player->printName(); // This is used when the class is a pointer (Heap memory)
    player->Move(3, 3);
    player->X = 2;

    Player player2 = Player("Andres");
    player2.printName(); // This is used when the class is an instance (Stack)
    player2.Move(3, 3);
    player2.X = 2;

    std::cin.get();
}