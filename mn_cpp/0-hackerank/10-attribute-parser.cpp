#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, Q;
    cin >> N >> Q;
    vector<vector<string>> Lines, Queries;

    for (int i = 0; i < N; i++)
    {
        string value;
        char tmp;
        stringstream str_stm;
        while (str_stm >> value)
        {
            Lines[i].push_back(value);
        };
    }

    for (int i = 0; i < Q; i++)
    {
        string value;
        char tmp;
        stringstream str_stm;
        while (str_stm >> value)
        {
            Queries[i].push_back(value);
        };
    }

    return 0;
}
