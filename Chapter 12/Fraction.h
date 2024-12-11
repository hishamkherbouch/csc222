#include <iostream>
#include <string>
#include <doctest.h>
using namespace std;

struct Fraction{
    int numerator;
    int denominator;

    Fraction(int,int);
    Fraction();
    Fraction(string);

    string to_string() const;
};
