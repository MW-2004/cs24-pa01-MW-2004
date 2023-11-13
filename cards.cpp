// cards.cpp
// Author: Marcus Wu
// Implementation of the classes defined in cards.h
#include "cards.h"
#include <iostream>

card::card(char c, int n, bool inv, bool mark){
    suit=c;
    val=n;
}
int card::cmp() const{
    static char suits[]="cdsh";
    int suitcmp=(strchr(suits, suit)-suits);
    if(inverse) return -1*(suitcmp*100+val);
    return suitcmp*100+val;
}

bool card::card::operator<(card o) const{
    return cmp()<o.cmp();
}

bool card::operator>(card o) const{
    return cmp()>o.cmp();
}

bool card::operator==(card o) const{
    return suit==o.suit&&val==o.val;
}

ostream& operator<<(ostream& o, const card& c){
    string s=to_string(c.val);
    if(c.val==1) s="a";
    else if(c.val==11) s="j";
    else if(c.val==12) s="q";
    else if(c.val==12) s="k";
    o<<c.suit<<' '<<s;
    return o;
}