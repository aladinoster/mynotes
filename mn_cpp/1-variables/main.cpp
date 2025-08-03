#include <iostream>

int main()
{
    int variable = 8;            // 4 bytes
    unsigned int variable2 = 10; // 4 bytes
    char a = 65;                 // 1 byte
    char car = 'a';              //
    short b = 2;                 // 2 bytes
    int c = 4;                   // 4 bytes
    long d = 5;                  // 4 bytes (complier conditioned)
    long int e = 6;              // 8 bytes
    float floating = 5.5f;       // 4 bytes
    double var = 5.2;            // 8 bytes
    bool decide = true;          // 1 byte

    std::cout << variable << std::endl;

    variable = 20;

    std::cout << variable << " " << sizeof(int) << std::endl;

    std::cout << variable2 << " " << sizeof(int) << std::endl;

    std::cout << a << car << " " << sizeof(char) << std::endl;

    std::cout << floating << " " << sizeof(float) << std::endl;

    std::cout << var << " " << sizeof(double) << std::endl;

    std::cout << decide << " " << sizeof(decide) << std::endl;

    std::cin.get();
}