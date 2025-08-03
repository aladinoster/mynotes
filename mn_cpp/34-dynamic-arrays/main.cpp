#include <iostream>
#include <vector>
#include <cstring>

struct Vertex
{
    float X, Y, Z;
    Vertex(float x, float y, float z) : X(x), Y(y), Z(z) {}
    Vertex(const Vertex &vertex) : X(vertex.X), Y(vertex.Y), Z(vertex.Z)
    {
        std::cout << "Copied!" << std::endl;
    }
};

std::ostream &operator<<(std::ostream &stream, const Vertex &vertex)
{
    stream << vertex.X << ", " << vertex.Y << ", " << vertex.Z << std::endl;
    return stream;
}

void function(const std::vector<Vertex> &vertices)
{
    for (int i = 0; i < vertices.size(); i++)
        std::cout << vertices[i];
}

int main()
{
    std::vector<Vertex> vertices;
    vertices.reserve(3); // Reserve 3 items. Taking out this line produces 6 constructors
    vertices.push_back({1, 2, 3});
    vertices.push_back({4, 5, 6});
    vertices.push_back(Vertex(7, 8, 9));

    std::vector<Vertex> vertices2; // no copies
    vertices2.reserve(3);
    vertices2.emplace_back(1, 2, 3); // Avoid the constructor in the vector
    vertices2.emplace_back(4, 5, 6);
    vertices2.emplace_back(7, 8, 9);

    // for (int i = 0; i < vertices.size(); i++)
    //     std::cout << vertices[i];

    function(vertices);

    vertices.erase(vertices.begin() + 1);

    for (Vertex &v : vertices)
        std::cout << v;

    std::cin.get();
}