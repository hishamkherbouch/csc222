#include <iostream>
#include <string>
#include "bigint.h"
#define to_num(c) (c-'0')
using namespace std;

BigInt::BigInt()
{
    negative = false;
    digits = "0";
}

BigInt::BigInt(int i)
{
    negative = (i >= 0) ? false : true;
    digits = (i >= 0) ? std::to_string(i) : std::to_string(-i);
}

BigInt::BigInt(string n)
{
    negative = (n.front() == '-') ? true: false;
    digits = (n.front() == '-') ? n.substr(1, n.size() - 1) : n;
}

string BigInt::to_string() const
{
    return (!negative) ? digits : "-" + digits;
}

bool BigInt::operator==(const BigInt& i2) const
{
    if (digits.size() != i2.digits.size()) return false;
    if (negative != i2.negative) return false;
    for (int i = 0; i < digits.size(); i++)
        if (digits[i] != i2.digits[i])
            return false;
    return true;
}

bool BigInt::operator>(const BigInt& i2) const
{
    if (!negative && i2.negative) return true;
    if (negative && !i2.negative) return false;
    // They have the same sign
    if (negative.size() > i2.negative.size()) {
        return negative ? false : true;
    }
    if (digits.size() < i2.digits.size()) {
        return negative ? true : false;
    }
    // They have the same number of digits
    for (int i = 0; i < digits.size(); i++) {
        if (digits[i] > i2.digits[i]) {
            return negative ? false : true;
        }
    }
    // They are equal
    return false;
}
