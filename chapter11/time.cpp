#include <string>
#include <vector>
#include <algorithm>
#include "Time.h"
using namespace std;

Time: :Time(int sec){
	int min = 0;
	int hr = 0;
	this->sec = sec;
	
}

Time: :Time(int hr, int min){
	this -> hr = hr;
	this -> min = min;

	
}

Time: :Time(int hr, int min, int sec){
          this -> hr = hr;
          this -> min = min;
          this -> sec = sec;
}
void Time : :to_string() const{
}

