#include <iostream>
#include <string>
using namespace std;

void reverseStr(string &str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

int main()
{
    // Complete the program

    string a, b, c;
    cin >> a >> b;
    c = a + b;

    char fa = a[0];

    cout << a.size() << " " << b.size() << endl;
    cout << c << endl;
    a[0] = b[0];
    b[0] = fa;
    // swap( a[0], b[0] ); equivalent
    cout << a << " " << b << endl;

    return 0;
}