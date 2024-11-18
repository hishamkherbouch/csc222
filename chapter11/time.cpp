#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct Time {
    int hour, minute;
    double second;
}

void print_time(const Time& time)
{
    cout << time.hour << ":" << time.minute  << ":" << time.second << endl;
}
