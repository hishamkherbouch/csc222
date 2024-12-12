#include <iostream>
#include <string>
#include <numeric>
#include <doctest.h>
#include "Fraction.h"
using namespace std;

Fraction::Fraction(){
    numerator=0;
    denominator=1;
}

Fraction::Fraction(int numerator, int denominator){
    this->numerator=numerator;
    this->denominator=denominator;
    int a = numerator;
    int b = denominator;
    while(b != 0){
        int temp = b;
        b = a  % b;
        a = temp;
    }
    this->numerator /= a;
    this->denominator /= a;
}

Fraction::Fraction(int numerator){
    this->numerator=numerator;
    denominator=1;
}
Fraction::Fraction(string word){
    int index = word.find("/");
    numerator=stoi(word.substr(0,index));
    denominator=stoi(word.substr(index+1));
}




string Fraction::to_string() const{
    if(denominator==1){
        return std::to_string(numerator);
    }
    else{
    return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
}
