#ifndef UTIL_CARD
#define UTIL_CARD
#include "cards.h"
#include <string>
#include <iostream>



#ifdef DEBUG
inline void print(){std::cout<<"\n";}
template<typename T1, typename ...T>
inline void print(const T1&first, const T&... t){
    std::cout<<first<<" ";
    print(t...);
}
#define _printnode(n, x) do{if(n->x) print(#x, n->x->val);else print("no",#x);}while(0)
#define printnode(n) do{if(!n)print("no ",n);else{\
    print(n, ": ",n->val);\
    _printnode(n,parent);\
    _printnode(n,left);\
    _printnode(n,right);}}while(0)
#else// #ifdef DEBUG
inline void print(){}
template<typename T1, typename ...T>
inline void print(const T1&first, const T&... t){
}
#define printnode(n) do{}while(0)
#endif// #ifndef DEBUG
using std::string, std::stoi;

card parsecard(string s, bool inv);
#endif //#ifndef UTIL_CARD