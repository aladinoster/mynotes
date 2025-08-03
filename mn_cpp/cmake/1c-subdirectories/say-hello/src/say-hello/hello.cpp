#include "hello.hpp"

#include <iostream>

void hello::say_hello()
{
    std::cout << "Hola Mundo! version" << SAY_HELLO_VERSION << std::endl;
}