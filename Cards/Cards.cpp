#include <iostream>
#include <vector>
#include <string>
#include "Cards.h"
using namespace std;

Card::Card(Suit suit,Rank rank){
    this->suit=suit;
    this->rank=rank;
}
Card::Card(){
    this->rank = JOKER;
}

string Card::to_string() const{
    vector<string> suit_strings = {"None", "Clubs", "Diamonds",
                               "Hearts", "Spades"};
    vector<string> rank_strings = {"Joker", "Ace", "2", "3", "4", "5", "6",
                                   "7", "8", "9", "10", "Jack", "Queen",
                                   "King"};
    if (rank == 0) return rank_strings[rank];
    return rank_strings[rank] + " of " + suit_strings[suit];
}
bool Card::operator==(const Card& c2, const Card& c1);
{
    return (c1.rank == c2.rank && c1.suit == c2.suit);
}
