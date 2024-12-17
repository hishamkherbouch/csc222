#include <iostream>
#include <vector>
#include <string>
#include "Cards.h"
using namespace std;

Card::Card(string suit, string rank){
    this->suit=suit;
    this->rank=rank;
}
Card::Card(){
    rank="Joker";
}
string Card::to_string() const
{
   return(rank + " of " + suit);
}
