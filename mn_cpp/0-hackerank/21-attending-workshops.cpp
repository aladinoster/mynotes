#include <bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int start_time;
    int duration;
    int end_time;
};
struct Available_Workshops
{
    int n;
    Workshop type[n];
    Available_Workshops(const int &m)
    {
        n = m;
    }
};

Available_Workshops *initialize(int start_time[], int duration[], int n)
{
    Available_Workshops *ws = new Available_Workshops(n);
    for (int i = 0; i < n; i++)
    {
        ws->type[i].start_time = start_time[i];
        ws->type[i].duration = duration[i];
        ws->type[i].end_time = start_time[i] + duration[i];
    }
    return ws;
};

int CalculateMaxWorkshops(Available_Workshops *ptr)
{
    int max_workshops;

    return max_workshops;
}

int main(int argc, char *argv[])
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    // cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
