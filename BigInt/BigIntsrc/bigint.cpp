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
bool BigInt::operator >= (const BigInt& other) const{
    return (this->operator > (other)) || (this->operator == (other));
}
bool BigInt::operator>(const BigInt& i2) const
{
    if (!negative && i2.negative) return true;
    if (negative && !i2.negative) return false;
    
    if (digits.size() > i2.digits.size()) {
        return negative ? false : true;
    }
    if (digits.size() < i2.digits.size()) {
        return negative ? true : false;
    }
    
    for (int i = 0; i < digits.size(); i++) {
        if (digits[i] > i2.digits[i]) {
            return negative ? false : true;
        }
    }
    
    return false;
}

bool BigInt::operator<(const BigInt& i2) const
{
    if (!negative && i2.negative) return false;
    if (negative && !i2.negative) return true;
  
    if (digits.size() > i2.digits.size()) {
        return negative ? true : false;
    }
    if (digits.size() < i2.digits.size()) {
        return negative ? false : true;
    }

    for (int i = 0; i < digits.size(); i++) {
        if (digits[i] > i2.digits[i]) {
            return negative ? true : false;
        }
    }

    return false;
}
bool BigInt::operator <= (const BigInt& other) const{
    return !(this->operator > (other));
}

bool BigInt::operator!=(const BigInt& i2) const
{
    return !(this->operator==(i2));
}



BigInt BigInt::operator+(const BigInt& i2) const
{
 string result = "";
    int c  = 0;
    
    int x = digits.size()-1;
    int y = i2.digits.size()-1;

    while(x>= 0 || y>=0 || c){
        int digit1 = (x >= 0) ? digits[x] - '0' : 0;
        int digit2 = (y >= 0) ? i2.digits[y] - '0' : 0;
        
        int sum = digit1 + digit2 + c;
        result.insert(result.begin(), (sum % 10) + '0');
        c = sum / 10;
        
        x--;
        y--;
    }

    return BigInt(result);

   
}

BigInt BigInt::operator-() const {
    BigInt result = *this;
    if(result.digits=="0"){
        return BigInt("0");
    }
    result.negative = !negative;
    return result;
}


BigInt BigInt::operator-(const BigInt& i2) const {
    if (this->negative && !i2.negative) {
        return -((-*this) + i2); 
    }
    if (!this->negative && i2.negative) {
        return *this + (-i2); 
    }
    if (this->negative && i2.negative) {
        return (-i2) - (-*this); 
    }

    if (*this < i2) {
        return -(i2 - *this); 
    }

    string result = "";
    string num1 = this->digits;
    string num2 = i2.digits;

    while (num1.size() < num2.size()) num1.insert(num1.begin(), '0');
    while (num2.size() < num1.size()) num2.insert(num2.begin(), '0');

    int borrow = 0;
    for (int i = num1.size() - 1; i >= 0; i--) {
        int diff = (num1[i] - '0') - (num2[i] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.insert(result.begin(), diff + '0');
    }

    while (result.size() > 1 && result.front() == '0') {
        result.erase(result.begin());
    }

    return BigInt(result);
}

BigInt BigInt::operator*(const BigInt& i2) const
{
    bool resultNegative = (this->negative != i2.negative);
  
    string result(this->digits.size() + i2.digits.size(), '0');
  
    for(int i=this->digits.size() -1; i>= 0; i--){
        int carry = 0;
        for(int j = i2.digits.size() -1; j >= 0; j--){
            int product = (this->digits[i]-'0') * (i2.digits[j]-'0')+(result[i+j+1]-'0')+ carry;
            carry = product / 10;
            result[i+j+1] = (product % 10) + '0';
        }
        result[i] += carry;
    }

    size_t startPos = result.find_first_not_of('0');
    if(startPos != string::npos){
        result = result.substr(startPos);
    }
    else{
        result = "0";
    }

    if(resultNegative && result != "0"){
        result.insert(result.begin(), '-');
    }

    return BigInt(result);
}
BigInt BigInt::operator/(const BigInt& i2) const
{

}
BigInt BigInt::operator%(const BigInt& i2) const
{
    
    
    
    if(i2==BigInt("0")){
        throw std::invalid_argument("Can not divide by zero");
    }
    
    BigInt dividend = *this;
    BigInt divisor = i2;

    bool isNegative = dividend.negative;

    if(dividend.negative){
        dividend = -dividend;
    }

    if(divisor.negative){
        divisor = -divisor;
    }

    if(dividend<divisor){
        return *this;
    }

    while(dividend>= divisor){
        dividend = dividend - divisor;
    }

    return isNegative ? -dividend : dividend;

}







