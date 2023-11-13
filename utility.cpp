#include "utility.h"

card parsecard(string s, bool inv){
    if(s[2]=='j') return card{s[0], 11, inv};
    if(s[2]=='q') return card{s[0], 12, inv};
    if(s[2]=='k') return card{s[0], 13, inv};
    if(s[2]=='a') return card{s[0], 1, inv};
    return card{s[0], stoi(s.substr(2,s.size())), inv};
}



ostream& operator<<(ostream& o, const BST& t){
    t._print(t.root);
    return o;
}

void BST::_print(BST::node *n) const {
    if(!n) return;
    _print(n->left);
    cout<<n->val<<" ";
    _print(n->right);
}
BST::BST(){
    root=0;
}
BST::~BST(){
    clear(root);
    root=0;//defensive
}

bool BST::insert(card c){
    if(root) return insert(c,root);
    root=new node(c);
    return 1;
}
bool BST::insert(card value, node *n) {
    card v=n->val;
    if(value==n->val) return 0;
    if(value<v){
        if(n->left) return insert(value, n->left);
        n->left=new node(value);
        n->left->parent=n;
        return 1;
    }
    if(n->right) return insert(value, n->right);
    n->right=new node(value);
    n->right->parent=n;
    return 1;
}

void BST::reverse_in_print() const{
    _reverse_in_print(root);
}
void BST::_reverse_in_print(node *n) const{
    if(!n) return;
    _reverse_in_print(n->right);
    cout<<n->val<<'\n';
    _reverse_in_print(n->left);
}
bool BST::contains(card value) const{
    if(!root) return 0;
    card tmp=value;
    tmp.inverse=root->val.inverse;
    return getNodeFor(tmp, root);
}
int BST::count(node *n) const {
    if(!n) return 0;
    return count(n->left)+count(n->right)+1;
}
BST::node *BST::getPredecessorNode(card value) const{
    node *n=getNodeFor(value, root);
    if(!n) return 0;
    if(n->left){
        n=n->left;
        while(n->right) n=n->right;
        return n;
    }
    #define isleftchild(node) node->parent&&node->parent->left==node
    while(isleftchild(n)) n=n->parent;
    if(n==root) return 0;
    return n->parent;
}

bool BST::remove(card value){
    if(!root) return 0;
    card tmp=value;
    tmp.inverse=root->val.inverse;
    node *n=getNodeFor(tmp, root);
    if(!n) return 0;
    if(count(root)==1){
        delete root;
        root=0;
        return 1;
    }

    node *pre=getPredecessorNode(n->val);
    while(pre){
        node *tmp=getPredecessorNode(pre->val);
        n->val=pre->val;
        n=pre;
        pre=tmp;
        if(!(n->left||n->right)) break;//optimization: no child
    }
    if(root==n){
        root=root->right;//root doesn't have pred
        delete n;
        return 1;
    }
    if(isleftchild(n)){
        n->parent->left=n->right;
        if(n->right) n->right->parent=n->parent;
    }else n->parent->right=0;//necessary after optimization
    delete n;
    return 1;
}

BST::node *BST::getNodeFor(card value, node *n) const{
    if(!n) return 0;
    if(value==n->val) return n;
    if(value<n->val) return getNodeFor(value, n->left);
    return getNodeFor(value, n->right);
}

void BST::clear(node *n){
    if(!n) return;
    
    clear(n->left);
    clear(n->right);
    delete n;
}

void BST::mark(card c){
    if(!root) return;
    card tmp=c;
    tmp.inverse=root->val.inverse;
    node *n=getNodeFor(tmp, root);
    if(!n) return;
    n->val.mark=1;
}