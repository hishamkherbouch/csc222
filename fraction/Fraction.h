#include <numeric>
#include <iostream>
#include <string>
#include <doctest.h>
using namespace std;

struct Fraction{
    int numerator;
    int denominator;

    Fraction(int,int);
    Fraction();
    Fraction(int);
    Fraction(string);
   
    int gcd(int, int);
    string to_string() const;
    float to_decimal();
};

