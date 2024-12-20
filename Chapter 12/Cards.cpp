#include <iostream>
#include <vector>
#include <string>
#include "Cards.h"
using namespace std;

Card::Card(int suit, int rank){
    this->suit=suit;
    this->rank=rank;
}
Card::Card(){
    suit =0;
    rank =0;
}
string Card::to_string() const
{
    vector<string> suit_strings = {"None", "Clubs", "Diamonds",
                                   "Hearts", "Spades"};
    vector<string> rank_strings = {"Joker", "Ace", "2", "3", "4", "5", "6",
                                   "7", "8", "9", "10", "Jack", "Queen",
                                   "King"};

    if (rank == 0) return rank_strings[rank];
    return rank_strings[rank] + " of " + suit_strings[suit];
}
