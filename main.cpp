//#define DEBUG

//#include "cards.h"
//#include "utility.h"
//#include "bst.h"
#include "cards.cpp"
#include "utility.cpp"
#include "bst.cpp"
#include <iostream>
#include <fstream>
#include <string>
inline void pprint(){std::cout<<"\n";}
template<typename T1, typename ...T>
inline void pprint(const T1&first, const T&... t){
    std::cout<<first<<" ";
    pprint(t...);
}
using namespace std;

int main(int argv, char** argc){
    print("start");
    string filename1="acards.txt";
    string filename2="bcards.txt";
    #ifdef DEBUG
    if(argv > 3){
        filename1=argc[1];
        filename2=argc[2];
    }
    #else
    if(argv<3){
        pprint("too few args");
        return 1;
    }
    #endif
    ifstream cardFile1 (filename1);
    ifstream cardFile2 (filename2);
    string line;
    if (cardFile1.fail() || cardFile2.fail() ){
        cout << "Could not open file " << argc[2];
        return 1;
    }
    BST t1;
    BST t2;
    //Read each file
    while (getline (cardFile1, line) && (line.length() > 0)){
        card c=parsecard(line, 0);
        t1.insert(c);
    }
    cardFile1.close();
    while (getline (cardFile2, line) && (line.length() > 0)){
        card c=parsecard(line, 1);
        t2.insert(c);
    }
    cardFile2.close();
    
    BST::Iterator it1=t1.begin(), it2=t2.begin();
    bool flag=1;
    vector<card>history;
    while(1){
        
        //print(flag,*it1, *it2,it1==t1.end(),it2==t2.end());
        if(it2==t2.end()) flag=1;
        if(it1==t1.end()) flag=0;
        if(it1==t1.end()&&it2==t2.end()) break;
        if(flag){
            if(!(*it1).mark&&t2.contains(*it1)){
                cout<<"Alice picked matching card "<<*it1<<'\n';
                t1.mark(*it1);
                t2.mark(*it1);
                history.push_back(*it1);
                flag=0;
            }
            ++it1;
        }else{
            if(!(*it2).mark&&t1.contains(*it2)){
                cout<<"Bob picked matching card "<<*it2<<'\n';
                t1.mark(*it2);
                t2.mark(*it2);
                history.push_back(*it2);
                flag=1;
            }
            ++it2;
        }
    }
    pprint();
    for(auto e:history){
        if(!t1.remove(e)) t1.remove(card{e.suit,e.val,!e.inverse});
    }
    for(auto e:history){
        if(!t2.remove(e)) t2.remove(card{e.suit,e.val,!e.inverse});
    }
    pprint("Alice's cards:");
    for(auto e: t1) pprint(e);
    pprint("\nBob's cards:");
    for(auto e: t2) pprint(e);
    return 0;
}
