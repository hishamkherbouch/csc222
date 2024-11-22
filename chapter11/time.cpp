#include "Time.h"
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

Time :: Time () : hr(0), min(0), sec(0){}

Time :: Time (int seconds){
    hr = seconds / 3600; 
    seconds  %= 3600;
    min = seconds  / 60;
    sec = seconds % 60;    
}
string time_to_string() const{
    string hour ="00" +  to_string(this->hr);
    string minute ="00" +  to_string(this->min);
    string second ="00" +  to_string(this->sec);
    return hour.substr(hour.size()-2,2) + ":" + 
           minute.substr(minute.size()-2,2) + ":" +
           second.substr(second.size()-2,2);
}

