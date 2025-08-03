#include <iostream>
#include <string>

// Dynamic casting is done at runtime // Performance issue

class Entity
{
public:
    virtual void PrintName() {}
};

class Player : public Entity
{
};

class Enemy : public Entity
{
};

int main(int argc, char const *argv[])
{
    Player *player = new Player();
    Entity *actuallyEnemy = new Enemy();

    Entity *actuallyPlayer = player; // Cast to a father class

    // Player *castplayer = (Player *)actuallyPlayer; // cast is used to ensure the compiler e is a player (dangerous)

    // Player *castplayer2 = (Player *)actuallyEnemy; // This is risky because if player does things that enemy does not ?? Error

    // C++ solves this by usging RunTime Type Information (RTTI)

    Player *castplayer3 = dynamic_cast<Player *>(actuallyEnemy); // Returns null when the cast does not work.

    //useful
    if (castplayer3)
    {
        // Do something
    }

    Player *castplayer4 = dynamic_cast<Player *>(actuallyPlayer); // Create

    return 0;
}
