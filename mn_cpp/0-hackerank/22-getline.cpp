#include <iostream>
#include <cstring>
#include <vector>

int main()
{
    std::string name;
    while (std::getline(std::cin, name))
    {
        std::getline(std::cin, name);
        std::vector<int> x;

        const char *c = name.c_str();
        for (int i = 0; i < name.size(); i++)
        {
            x.push_back(std::stoi(&name[i]));
        }
    }

    return 0;
}