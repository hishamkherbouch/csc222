#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Card
{
    int suit, rank;

    Card();
    Card(int s, int r);
    string to_string() const;
    bool Card operator==(const Card& c2, const Card& c1);
};

