#include "utility.h"

card parsecard(string s, bool inv){
    if(s[2]=='j') return card{s[0], 11, inv};
    if(s[2]=='q') return card{s[0], 12, inv};
    if(s[2]=='k') return card{s[0], 13, inv};
    if(s[2]=='a') return card{s[0], 1, inv};
    return card{s[0], stoi(s.substr(2,s.size())), inv};
}


