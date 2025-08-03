#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, Q;

    cin >> N >> Q;

    vector<vector<int>> Vectors, Queries;

    for (int i = 0; i < N; i++)
    {
        int KSize, value;
        cin >> KSize;
        vector<int> tmp;
        for (int j = 0; j < KSize; j++)
        {
            cin >> value;
            tmp.push_back(value);
        }
        Vectors.push_back(tmp);
    }

    for (int i = 0; i < Q; i++)
    {
        int value1, value2;
        vector<int> tmp;
        cin >> value1 >> value2;
        tmp.push_back(value1);
        tmp.push_back(value2);
        Queries.push_back(tmp);
    }

    for (int i = 0; i < Queries.size(); i++)
    {
        int q = Queries[i][0];
        int v = Queries[i][1];
        cout << Vectors[q][v] << endl;
    }
    return 0;
}