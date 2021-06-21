#include <iostream>
#include <utility>
#include "treeBasic.cpp"
using namespace std;

bool heightBalance(node* root){
    if(root == nullptr)
        return true;

    int l = height(root->left);
    int r = height(root->right);

    if(l - r > 1)
        return false;

    return true;
}

pair<int,bool> heightBalance_opt(node* root){
    
    pair<int, bool> p;

    // base case
    if(root == nullptr){
        p.second = true;
        p.first = 0;
        return p;
    }

    // post-order recursion
    pair<int,bool> l = heightBalance_opt(root->left);
    pair<int,bool> r = heightBalance_opt(root->left);

    p.first = max(l.first,r.first) + 1; // height of the tree

    if(abs(l.first - r.first) <= 1 and l.second == true and r.second == true)
        p.second = true; // for balance

    return p;
}

int main(){

    node* root = preOrderBuild();

    levelOrder(root);
    cout << endl;

    pair<int,bool> r = heightBalance_opt(root);

    cout << r.second << endl;

    return 0;
}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
