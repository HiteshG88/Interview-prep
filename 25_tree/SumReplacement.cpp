#include <iostream>
#include "treeBasic.cpp"
using namespace std;

int SumReplace(node* root){

    if(root == nullptr)
        return 0;

    if(root->left == nullptr and root->right == nullptr)
        return root->data;

    int temp = root->data;

    int left = SumReplace(root->left);
    int right = SumReplace(root->right);

    root->data = left+right;

    return temp + root->data;
}

int main(){

    node* root = preOrderBuild();

    levelOrder(root);
    cout << endl;

    SumReplace(root);

    levelOrder(root);
    cout << endl;

    return 0;
}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
