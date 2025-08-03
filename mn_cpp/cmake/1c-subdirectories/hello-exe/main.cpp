#include <iostream>
#include "say-hello/hello.hpp"
int main()
{
    hello::say_hello();
    std::cout << "This is executable with library cd" << SAY_HELLO_VERSION << std::endl;
}