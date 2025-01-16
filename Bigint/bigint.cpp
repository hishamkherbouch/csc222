#include <iostream>
#include <string>
#include "bigint.h"
#define to_num(c) (c-'0')
using namespace std;

BigInt::BigInt()
{
    flag = false;
    digits = "0";
};
