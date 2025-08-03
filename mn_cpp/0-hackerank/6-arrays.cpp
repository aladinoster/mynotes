#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int N, i = 0;
    cin >> N;
    vector<int> a;

    while (cin >> i)
    {
        a.push_back(i);
    }

    reverse(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
    }
    return 0;
}
