#ifndef UTIL_CARD
#define UTIL_CARD
#include "cards.h"
#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::stoi;

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



card parsecard(string s, bool inv);

class BST{
public:
    struct node{
        card val;
        node *left, *right, *parent;
        node(card v): val(v), left(0), right(0), parent(0){}
    };
    BST();
    ~BST();
    bool insert(card c);
    bool contains(card value) const;
    node *getPredecessorNode(card value) const;
    bool remove(card value);
    int count(node *n) const;
    void mark(card c);
    class Iterator {
    public:
        std::vector<node*> nodeStack;
        node *current;
        Iterator(node *root) {
            current = root;
            while (current != nullptr || !nodeStack.empty()) {
                while (current != nullptr) {
                    nodeStack.push_back(current);
                    current = current->left;
                }
                current = nodeStack.back();
                nodeStack.pop_back();
                break;
            }
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current || !nodeStack.empty();
        }
        bool operator==(const Iterator& other) const {
            return !(*this!=other);
        }

        Iterator& operator++() {
            current=current->right;
            while (current != nullptr || !nodeStack.empty()) {
                while (current != nullptr) {
                    nodeStack.push_back(current);
                    current = current->left;
                }
                current = nodeStack.back();
                nodeStack.pop_back();
                break;
            }
            return *this;
        }

        card operator*() const {
            if(!current) return card{'e',-1};
            return current->val;
        }
    };

    Iterator begin() const {
        return Iterator(root);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }

private:
    node *root;

    bool insert(card value, node *n);
    node *getNodeFor(card value, node *n) const;
    void clear(node *n);
    void _print(node *n) const;
    friend ostream& operator<<(ostream& o, const BST& t);
};
#endif //#ifndef UTIL_CARD