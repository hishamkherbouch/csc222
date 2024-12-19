#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Card
{
    Suit suit;
    Rank rank;

    string to_string() const;
    
    Card();
    Card(Suit, Rank); 
    string to_string() const;
    bool  operator==(const Card& c2) const;
};

