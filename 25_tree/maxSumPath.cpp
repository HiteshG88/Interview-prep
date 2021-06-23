#include <iostream>
#include "treeBasic.cpp"
using namespace std;

class Pair{
public:
    int maxSum, branchSum;
    Pair(){
        maxSum = branchSum = 0;
    }
};


Pair maxSumPath(node* root){

    Pair p;

    // base case
    if(root == nullptr)
        return p;

    // recursive calls
    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    // the max sum path of the tree could be inclusive of root or exclusive of root
    // maxSumPath = max of (path_include_root, path_left, path_right)

    // the most imp case is path_include_root as other 2 will also boil down to this case
    int op1 = root->data;
    int op2 = root->data + left.branchSum;
    int op3 = root->data + right.branchSum;
    int op4 = root->data + right.branchSum + left.branchSum;

    int current_ans_through_root = max(op1,max(op2, max(op3, op4)));

    // compute the branchSum:
    // branchSum will always include root->data and 0 is there to not return max as negetive
    p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root->data;

    // compute the maxSum:
    p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_through_root));

    return p;
}


int main(){
    node* root = nullptr;

    root = preOrderBuild();
    levelOrder(root);

    cout << maxSumPath(root).maxSum << endl;
}

// 10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1
