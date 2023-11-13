#define DEBUG
#include <iostream>
#include <vector>
#include "cards.h"
#include "utility.h"
using namespace std;
int main(){
    BST b;
    b.insert(card{1,2});
    b.insert(card{3,4});
    print(&b);
}