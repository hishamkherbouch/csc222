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
bool Card::operator == (const Card& c1) const {
    return rank == c1.rank && suit == c1.suit;
}
bool Card::operator != (const Card& c1) const {
    return !(*this == c1);
}
bool Card::operator < (const Card& c1) const {
    if(rank == c1.rank){
        return suit < c1.suit;
    }
    return rank <  c1.rank;
}
bool Card::operator > (const Card& c1) const {
    return c1 < *this;
}
