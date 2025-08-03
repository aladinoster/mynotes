#include <iostream>
#include <vector>
#include <unordered_map>

#define LOG(X) std::cout << X << std::endl;

std::string get_name() // with auto you could change std:string to char*
{
    return "Cherno";
}

auto get_name_auto() -> int // Cpp+11
{
    return 1;
}

class Device
{
};

class DeviceManager
{
private:
    std::unordered_map<std ::string, std::vector<Device *>> m_Devices;

public:
    const std::unordered_map<std ::string, std::vector<Device *>> &GetDevices() const
    {
        return m_Devices;
    }
};

int main(int argc, char const *argv[])
{
    int a = 1;
    auto b = a;
    auto c = "Cherno";
    auto d = 2L;
    auto e = 2.0f;
    auto f = 2.0;
    auto h = 'a';

    auto name = get_name();

    LOG(b);

    std::vector<std::string> strings;
    strings.push_back("Oranges");
    strings.push_back("Apples");

    for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
    {
        LOG(*it);
    }

    for (auto it = strings.begin(); it != strings.end(); it++)
    {
        LOG(*it);
    }

    using DeviceMap = std::unordered_map<std ::string, std::vector<Device *>>; // Like namespaces

    typedef std::unordered_map<std ::string, std::vector<Device *>> DeviceMap; // Alias for type definition.

    DeviceManager dm;
    const DeviceMap &devices = dm.GetDevices();

    const auto &devices2 = dm.GetDevices(); // Another way // keep in mind you are returning a reference.

    std::cin.get();
}
