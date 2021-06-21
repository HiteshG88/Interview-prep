#include <iostream>
#include "treeBasic.cpp"
using namespace std;

// assumption both a and b are present in the tree and all the values are unique
node* lca(node* root, int a, int b){

    // base case
    if(root == nullptr)
        return nullptr;

    // check if a or b present in root
    if(root->data == a or root->data == b)
        return root;

    // find lca in left and right
    node* left_ans = lca(root->left, a, b);
    node* right_ans = lca(root->right, a, b);

    // if a and b are present in left and right then return the root
    if(left_ans != nullptr and right_ans != nullptr)
        return root;

    // if only one left part have a or b return it
    if(left_ans != nullptr)
        return left_ans;

    // else return right
    return right_ans;
}

int main(){

    node* root = preOrderBuild();

    levelOrder(root);
    cout << endl;

    root = lca(root, 6, 0);

    cout << root->data << endl;

    return 0;
}

// 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
