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


std::string Time::time_to_string() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hr << ":"
        << std::setfill('0') << std::setw(2) << min << ":"
        << std::setfill('0') << std::setw(2) << sec;
    return oss.str();
}


