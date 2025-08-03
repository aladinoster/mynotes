#include <bits/stdc++.h>

using namespace std;

class Box
{
private:
    int l, b, h;

public:
    Box() : l{0}, b{0}, h{0} {}
    Box(int length, int base, int height) : l{length}, b{base}, h{height} {}
    Box(const Box &other) : l(other.l), b(other.b), h(other.h) {}
    int getLength() { return l; }                                // Return box's length
    int getBreadth() { return b; }                               // Return box's breadth
    int getHeight() { return h; }                                //Return box's height
    long long CalculateVolume() { return (long long)l * b * h; } // Return the volume of the box
    friend ostream &operator<<(ostream &out, const Box &B);

    bool let(const Box &other) const
    {
        bool value = (l < other.l) || (b < other.b && l == other.l) || (h < other.h && b == other.b && l == other.l);
        return value;
    }

    bool operator<(const Box &other) const
    {
        return let(other);
    }
};

ostream &operator<<(ostream &out, const Box &B)
{
    out << B.l << " " << B.b << " " << B.h;
    return out;
}

//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);

// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main()
{
    check2();
}