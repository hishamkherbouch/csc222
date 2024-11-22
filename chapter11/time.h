#ifndef TIME_H
#define TIME_H
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Time {
    int sec, min, hr;

    Time();                    
    Time(int seconds);               
    Time(int hour, int minute);
    Time(int hour, int minute, int seconds);
    string time_to_string() const;
};
#endif
