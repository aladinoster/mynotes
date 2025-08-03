#include <iostream>
#include <cstring>

struct Vector2
{
    float x, y;
};

class String
{
private:
    char *m_Buffer;
    unsigned int m_Size;

public:
    String(const char *string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1]; // For null character
        // for(int i=0;i<m_Size;i++)
        //     m_Buffer[i]=string[i]
        memcpy(m_Buffer, string, m_Size); // Assumes that the char is properly
        m_Buffer[m_Size] = 0;
    }

    // Our copy constructor
    String(const String &other) : m_Size(other.m_Size)
    {
        std::cout << "Creating Copy" << std ::endl;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }
    //Copy Constructor(Default)
    // String(const String &other) : m_Buffer(other.m_Buffer), m_Size(other.m_Size)
    // {
    // }

    // In case you dont want String x = y;
    //  String(const String &other) = delete;

    // More interesting copy constructor
    // String(const String &other)
    // {
    //     memccpy(this, &other, sizeof(String));

    // }

    ~String()
    {
        delete m_Buffer;
    }

    friend std::ostream &operator<<(std::ostream &stream, const String &string);

    char &operator[](unsigned int index)
    {
        return m_Buffer[index];
    }
};

std::ostream &operator<<(std::ostream &stream, const String &string)
{
    stream << string.m_Buffer; // since it is friend this function can access string members
    //Otherwise a method is required to be implemented string.Get_Buffer();
    return stream;
}

void PrintString(const String &string)
{
    std::cout << string << std::endl;
}

void InefficientPrint(String string)
{
    std::cout << string << std::endl;
}

int main()
{
    // Copy
    Vector2 a = {1, 2};
    Vector2 b = a;
    b.x = 5;

    // Pointer
    Vector2 *e = new Vector2();
    Vector2 *f = e;
    f->x = 2;

    {
        int c = 2;
        int d = c; // This is a copy of the c. In objects this is a shallow copy.

        String string = "Cherno";
        String second = string; // When destructing we are destrcting a char pointer. For the second destructor it does not exist so this is the error. We free the memory twice;

        second[2] = 'a';

        PrintString(string);
        PrintString(second);

        InefficientPrint(string); // this creates a call to the constructor so pass by reference
    }
}