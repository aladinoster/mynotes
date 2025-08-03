#include <iostream>

#define LOG(x) std::cout << x << std::endl

//#define struct class  -> Recover backwards compatibility by changing struct to class (but be carefull)

/*
Struct: POD Plain Old Data (Complex data formats)
Class: Use it when inheritance
*/

class Player
{
public:
    int x, y; // default is private in classes
    int speed;
    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};
struct Playero //comes from C
{
    int x, y;
    int speed;
    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};

int main()
{

    Player player;
    player.Move(1, -1);
    Playero playero;
    playero.Move(1, -1);

    std::cin.get();
}