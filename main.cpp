#include "utility.h"
#include "cards.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argv, char** argc){
    if(argv<3){
        cout<<"too few args\n";
        return 1;
    }
    string filename1=argc[1];
    string filename2=argc[2];
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
    cout<<'\n';
    for(auto e:history){
        !t1.remove(e);
    }
    for(auto e:history){
        t2.remove(e);
    }
    cout<<"Alice's cards:"<<'\n';
    for(auto e: t1) cout<<e<<'\n';
    cout<<"\nBob's cards:"<<'\n';
    for(auto e: t2) cout<<e<<'\n';
    return 0;
}
