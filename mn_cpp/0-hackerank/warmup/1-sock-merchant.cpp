#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

#include <algorithm>

bool lookForValue(int value, vector<int> ar)
{
    for (auto &v : ar)
        if (v == value)
            return true;
    return false;
}

template <typename T>
vector<T> s(vector<T> const &v, int m, int n)
{
    auto first = v.begin() + m;
    auto last = v.begin() + n + 1;
    vector<T> vector(first, last);
    return vector;
}

int sockMerchant(int n, vector<int> ar)
{
    int n_pairs = 0;
    vector<int> cum_pairs;
    for (int i = 0; i < ar.size(); i++)
    {
        if (lookForValue(ar[i], cum_pairs))
        {
            n_pairs++;
            auto it = std::find(cum_pairs.begin(), cum_pairs.end(), ar[i]);
            cum_pairs.erase(it);
        }
        else
        {
            cum_pairs.push_back(ar[i]);
        }
    }
    return n_pairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split(rtrim(ar_temp_temp));

    vector<int> ar(n);

    for (int i = 0; i < n; i++)
    {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = sockMerchant(n, ar);

    fout << result << "\n";

    fout.close();

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
