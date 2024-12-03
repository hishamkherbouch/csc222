#include<Car.h>
#include<string>
#include<iostream>

using namespace std;

Car::Car(string brand, string color, string model, int year, float miles, double gasTank){
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

    
