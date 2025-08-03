//Operator Overloading

#include <iostream>
#include <ostream>

using namespace std;

class Complex
{
public:
    int a, b;
    void input(string s)
    {
        int v1 = 0;
        int i = 0;
        while (s[i] != '+')
        {
            v1 = v1 * 10 + s[i] - '0';
            i++;
        }
        while (s[i] == ' ' || s[i] == '+' || s[i] == 'i')
        {
            i++;
        }
        int v2 = 0;
        while (i < s.length())
        {
            v2 = v2 * 10 + s[i] - '0';
            i++;
        }
        a = v1;
        b = v2;
    }
    // Complex operator+(const Complex &other)
    // {

    //     int af = a + other.a;
    //     int bf = b + other.b;
    //     Complex c = Complex();
    //     c.input(to_string(af) + "+" + to_string(bf) + "i");
    //     return c;
    // }
};

Complex operator+(const Complex &first, const Complex &second)
{

    int af = first.a + second.a;
    int bf = first.b + second.b;
    Complex c = Complex();
    c.input(to_string(af) + "+i" + to_string(bf));
    return c;
}

ostream &operator<<(ostream &stream, const Complex &object)
{
    stream << object.a << "+i" << object.b;
    return stream;
}

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

int main()
{
    Complex x, y;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    x.input(s1);
    y.input(s2);
    Complex z = x + y;
    cout << z << endl;
}
