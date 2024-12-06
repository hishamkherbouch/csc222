#include"Car.h"
#include<string>
#include<iostream>

using namespace std;

Car::Car(string brand, string color, string model, int year, int miles, double gasTank){
    this->brand=brand; this->color=color; this->model=model; this->year=year; this->miles=miles; this->gasTank=gasTank;
}
string to_string_double(double x){
    return std::to_string(int(x)) + '.' + std::to_string(int((x-int(x)) * 100));
}
void Car::Drive (int driveMiles){
    double gasLeft = gasTank - driveMiles * 0.05;
    if(gasLeft<=0){
        cout<<"You don't have enough gas."<<endl;
    }
    else{
        gasTank = gasLeft;
        miles += driveMiles;
        cout<<"Trip succesful.You have " + to_string_double(gasTank) +  " % of the tank left "<<endl;
    }
}

void Car::FillTank () {
    gasTank = 100.0;
}

string Car::to_string() const{
    return "Brand " + brand + "; Color " + color + "; Model " + model + "; Year " +std::to_string(year) + "; Miles " +std::to_string(miles) + "; Gas tank " + to_string_double(gasTank);
};
