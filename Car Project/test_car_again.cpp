#include "Car.h"
#include <iostream>
using namespace std;

int main() {
    Car Daily("Audi", "Black", "Q5", 2017, 75238, 30.6);

    cout<<Daily.to_string()<<endl;

    Car Racer("Dodge", "Red", "Hellcat SRT", 2024, 5142, 2.3);

    cout<<Racer.to_string()<<endl;

    Daily.Drive(12);

    Daily.FillTank();

    Racer.Drive(50);

    Racer.FillTank();

    Racer.Drive(50);
    
    Car suri("Nissan","Blue",  "Rogue", 2017, 100000, 3);

    cout<<suri.to_string()<<endl;

    

}
