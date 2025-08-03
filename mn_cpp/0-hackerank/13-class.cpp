#include <iostream>
#include <sstream>
using namespace std;

string int_to_str(int x)
{
    stringstream ss;
    ss << x;
    return ss.str();
}

class Student
{
private:
    int age;
    string first_name;
    string last_name;
    int standard;

public:
    void set_age(int value)
    {
        age = value;
    }
    int get_age()
    {
        return age;
    }
    void set_first_name(string name)
    {
        first_name = name;
    }
    string get_first_name()
    {
        return first_name;
    }
    void set_last_name(string last)
    {
        last_name = last;
    }
    string get_last_name()
    {
        return last_name;
    }
    void set_standard(int stand)
    {
        standard = stand;
    }
    int get_standard()
    {
        return standard;
    }
    string to_string()
    {
        return int_to_str(age) + "," + first_name + "," + last_name + "," + int_to_str(standard);
    }
};
/*
Enter code for class Student here.
Read statement for specification.
*/

int main()
{
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}