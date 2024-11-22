#include "Time.h"
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

Time::Time() : hr(0), min(0), sec(0) {}


Time::Time(int sec) {
    hr = sec / 3600;
    sec %= 3600;
    min = sec / 60;
    this->sec = sec % 60;
}




string Time::time_to_string() const {
   string hour = to_string(hr);
   string minute = to_string(min);
   string second = to_string(sec);
   return hour + ":" + minute + ":" + second;
}

