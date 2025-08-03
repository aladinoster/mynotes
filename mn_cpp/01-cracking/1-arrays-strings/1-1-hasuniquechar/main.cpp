#include <iostream>

bool isUniqueChar(std::string str)
{
    if (str.length() > 128)
        return 0;

    bool char_set[128] = {false};
    for (unsigned i = 0; i < str.length(); i++)
    {
        int val = str.at(i);

        if (char_set[val])
        {
            return false;
        }
        char_set[val] = true;
    }
    return true;
}

int main()
{

    std::string str("amor");
    std::cout << "Test for the word: " << str << std::endl;
    std::cout << isUniqueChar(str) << std::endl;

    return 0;
}