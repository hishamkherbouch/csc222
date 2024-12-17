#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Card{
    string rank;
    string suit;

    string to_string() const;
    
    Card(string, string);
    Card();
};
