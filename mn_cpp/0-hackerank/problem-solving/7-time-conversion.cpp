#include <bits/stdc++.h>
#include <string>
#include <cstring>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    auto daytime = s.substr(8, 2);
    if (daytime.compare("P"))
        return s.substr(0, 8);
    string time_reg = s.substr(0, 2);
    int time_mil = stoi(time_reg) + 12;
    string new_time = to_string(time_mil);
    auto final = new_time + s.substr(2, 6);
    return final;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
