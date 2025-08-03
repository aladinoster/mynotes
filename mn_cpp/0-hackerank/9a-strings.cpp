
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    stringstream str_strm("23,4,56");
    char ch;
    int a, b, c;
    str_strm >> a >> ch >> b >> ch >> c; // a = 23, b = 4, c = 56

    return 0;
}
