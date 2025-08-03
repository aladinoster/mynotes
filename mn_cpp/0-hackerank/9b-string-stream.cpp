#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string str("Hello from the dark side");
    string tmp; // A string to store the word on each iteration.
    stringstream str_strm(str);
    vector<string> words; // Create vector to hold our words
    while (str_strm >> tmp)
    {
        // Provide proper checks here for tmp like if empty
        // Also strip down symbols like !, ., ?, etc.
        // Finally push it.
        words.push_back(tmp);
    }
    for (int i = 0; i < words.size(); i++)
        cout << words[i] << endl;
}