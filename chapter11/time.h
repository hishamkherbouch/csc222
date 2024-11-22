#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Time {
    int sec, min, hr;

    Time();                    
    Time(int sec);               
    
    string time_to_string() const;
};

