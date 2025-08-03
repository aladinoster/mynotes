#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    vector<vector<int>> a;
    vector<int> l1 = {1, 2, 3};
    vector<int> l2 = {4, 5, 6};
    vector<int> l3 = {7, 8, 9};
    a.push_back(l1);
    a.push_back(l2);
    a.push_back(l3);

    vector<vector<int>> d;

    // for (auto &v : a)
    // {
    //     for (auto &z : v)
    //         cout << z << ", ";
    //     cout << endl;
    // }

    vector<vector<int>> c1(a.begin(), a.begin() + 1);

    for (auto &v : c1)
    {
        for (auto &z : v)
            cout << z << ", ";
        cout << endl;
    }
}