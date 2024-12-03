#include<Car.h>
#include<string>
#include<iostream>

using namespace std;

Car::Car(string brand, string color, string model, int year, int miles, double gasTank){
    this->brand=brand; this->color=color; this->model=model; this->year=year; this->miles=miles; this->gasTank=gasTank;
}

void Car::Drive(int driveMiles){
    double gasLeft = gasTank - driveMiles * 0.05;
    if(gasLeft<=0){
        cout<<"You can't drive that far. You need more gas"<<endl;
    }
    else{
        gasTank = gasLeft;
        miles += driveMiles;
        cout<<"Trip succesful.You have  " + gasTank " gas left"<<endl;
    }
}

void Car::FillTank(){
    gasTank = 100;
}

string to_string_double(double x) {
    return std::to_string(int(x)) + '.' + std::to_string(int((x - int(x)) * 100));
}
string Car::to_string() const{
    return "Brand " + brand + "; Color " + color + "; Model " + model + "; Year " + to_string(year) + "; Miles " + miles + "; Gas tank " + to_string_double(gasTank);
}
