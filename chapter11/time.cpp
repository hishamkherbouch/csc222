#include "Time.h"
#include <iomanip> 
#include <sstream>  


Time::Time() : hr(0), min(0), sec(0) {}


Time::Time(int seconds) {
    hr = seconds / 3600;      
    seconds %= 3600;          
    min = seconds / 60;       
    sec = seconds % 60;        
}

Time :: Time(int hour, int minute){
    hr = hour;
    min = minute;
    sec = 0;
}

Time :: Time(int hour, int minute, int second){
    hr = hour;
    min = minute;
    sec = second;
}

std::string Time::time_to_string() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(1) << hr << ":"
        << std::setfill('0') << std::setw(2) << min << ":"
        << std::setfill('0') << std::setw(2) << sec;
    return oss.str();
}
Time operator+(const Time& t1, const Time& t2){
   int total_sec = t1.sec + t2.sec;
   int total_min = t1.min + t2.min + (total_sec/60);
   total_sec %= 60;
   int total_hr = t1.hr + t2.hr + (total_min / 60);
   total_min %= 60;

   return Time(total_hr, total_min, total_sec);

}
    

