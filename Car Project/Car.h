#include <string>
#include <iostream>

using namespace std;

struct Car{
    string brand;
    string color;
    string model;
    int year;
    int miles;
    double gasTank;
    
    void Drive(int distance);
    void FillTank() ;
    string to_string() const;
    Car(string, string, string, int, int, double);
};
