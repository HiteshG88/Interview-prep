#include <iostream>
#include <vector>
#include "treeBasic.cpp"
using namespace std;

/*===================================================================
=            shortest distance btw 2 nodes coding blocks            =
===================================================================*/
/**
 *
 * 1. find the lowest common ancester of the 2 node.
 * 2. find the levels node a and node b from lca l1 and l2 respectovely
 * 3. return the sum of l1 and l2
 *
 * time O(n)
 * space O(height)
 */

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

int level(node* root, int k, int l){

    if(root == nullptr)
        return -1;

    if(root->data == k)
        return l;

    int left = level(root->left, k, l+1);
    if(left != -1)
        return left;
    return level(root->right, k, l+1);
}

int shortestDist(node* root, int a, int b){

    node* lca_node = lca(root, a, b);

    int l1 = level(lca_node, a, 0);
    int l2 = level(lca_node, b, 0);

    return l1+l2;
}


int main(){
    node* root = nullptr;

    root = preOrderBuild();

    levelOrder(root);
    cout << endl;

    cout << shortestDist(root, 3, 6);

    return 0;
}

// 10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1
// 4 2 1 -1 -1 3 -1 -1 5 7 -1 -1 6 -1 -1
