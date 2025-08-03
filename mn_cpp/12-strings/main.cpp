#include <iostream>
#include <string> // Required for cout overload for << is on this
#include <cstring>

void PrintString(const std::string &name) // not copying the string
{
    std::cout << name << std::endl;
}

int main()
{
    const char *name = "Andres"; // c-style  - immutable string (pointer)

    // name[4] = 'o'; // Never do this on apointer. Deprecated on C++11

    char name4[] = "Andres";
    name4[4] = 'o';

    std::cout << name4 << std::endl;

    char name2[6] = {'A', 'n', 'd', 'r', 'e', 's'};       // No null character.
    char name3[7] = {'A', 'n', 'd', 'r', 'e', 's', '\0'}; // Setting manually null character.

    std::cout << "Name is: " << name << std::endl;
    std::cout << "Size of: " << strlen(name) << std::endl;
    std::cout << "Name3 is: " << name3 << std::endl;
    std::cout << "Name2 is: " << name2 << std::endl;

    std::string sname = "Andres";
    std::cout << "String Name is: " << sname << std::endl;
    std::cout << "String size is: " << sname.size() << std::endl;

    std::string slast = " Ladino";
    std::string sfullname = sname + slast;

    sfullname += " Lopez"; // other way to add strings ;)
    std::cout << sfullname << std::endl;

    std::cout << sfullname.find("Lopez") << std::endl; // index

    PrintString(sfullname);
    std::cin.get();
}