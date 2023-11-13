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
    char suit;
    int val;
    bool inverse;
    bool mark;
    card(char c, int n, bool inv=false, bool m=0){
        suit=c;
        val=n;
        inverse=inv;
        mark=m;
    }
    int cmp() const;
    bool operator<(card o) const;
    bool operator>(card o) const;
    bool operator==(card o) const;

    friend ostream& operator<<(ostream& o, const card& c);
};
#endif //#ifndef CARDS_H