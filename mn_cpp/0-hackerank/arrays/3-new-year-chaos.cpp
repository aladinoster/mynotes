#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

vector<int> merge(vector<int> a, vector<int> b, int &counter)
{
    vector<int> c;
    while (~a.empty() && ~b.empty())
    {
        if (a[0] > b[0])
        {
            c.push_back(b[0]);
            b.erase(b.begin());
            counter++;
        }
        else
        {
            c.push_back(a[0]);
            a.erase(a.begin());
            counter++;
        }
    }
    while (~a.empty())
    {
        c.push_back(a[0]);
        a.erase(a.begin());
        counter++;
    }
    while (~b.empty())
    {
        c.push_back(b[0]);
        b.erase(b.begin());
        counter++;
    }
    return c;
}

vector<int> mergesort(vector<int> a, int &counter)
{
    if (a.size() == 1)
        return a;

    vector<int> arrayOne, arrayTwo;
    for (int i = 0; i < a.size() / 2; i++)
        arrayOne.push_back(a[i]);

    for (int i = a.size() / 2 + 1; i < a.size(); i++)
        arrayTwo.push_back(a[i]);

    vector<int> R1 = mergesort(arrayOne, counter);
    vector<int> R2 = mergesort(arrayTwo, counter);

    return merge(R1, R2, counter);
}

void minimumBribes(vector<int> q)
{
    int ans = 0;
    for (int i = q.size() - 1; i >= 0; i--)
    {
        if (q[i] - (i + 1) > 2)
        {
            cout << "Too chaotic" << endl;
            return;
        }
        for (int j = max(0, q[i] - 2); j < i; j++)
            if (q[j] > q[i])
                ans++;
    }
    cout << ans << endl;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++)
        {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
