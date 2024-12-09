#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Card{
    int rank;
    int suit;

    string to_string() const;
    
    Card(int, int);
    Card();
    Card(int);
};
