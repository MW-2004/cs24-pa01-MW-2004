// cards.h
// Author: Marcuds Wu
// All class declarations go here
#ifndef CARDS_H
#define CARDS_H
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct card{
    card(char c, int n, bool inv=0, bool mark=0);
    char suit;
    int val;
    bool inverse;
    bool mark;
    int cmp() const;
    bool operator<(card o) const;
    bool operator>(card o) const;
    bool operator==(card o) const;
    friend ostream& operator<<(ostream& o, const card& c);
};
#endif //#ifndef CARDS_H