#include <iostream>
#include <vector>
#include "treeBasic.cpp"
using namespace std;

// shortest distance between 2 nodes can be stated as (let 2 nodes be a and b):
// 1. find the path to a from root.
// 2. find the path to b from the root.
// 3. traverse the 2 array to find the common node. and them del the distance btw root and that common node.
// 4. now print one array in reverse and one in forward to get full path

/*========================
// * time O(n)
// * space O(height of tree)
========================*/

bool nodePath(node* root, int key, vector<int>& v){

    if(root == nullptr)
        return false;

    v.push_back(root->data);

    if(root->data == key)
        return true;

    // if any of the root node contain key return true
    if(nodePath(root->left, key, v) or nodePath(root->right, key, v))
        return true;

    // if key is not present both left and right of root the pop that root from v, and return false
    v.pop_back();
    return false;
}

static int size = 0;

void printPath(node* root, int k1, int k2){

    vector<int> v1;
    vector<int> v2;

    // pointer to the last common element.
    int i;

    if(nodePath(root, k1, v1) and nodePath(root, k2, v2)){

        for(i = 0; i < max(v1.size(), v2.size()); i++)
            if(v1[i] == v2[i]) break;

    }
    else{
        cout << "nodes not present in tree";
    }

    for(int j = v2.size()-1; j > i; j--){
        cout << v2[j] << " ";
        size++;
    }

    for(; i < v1.size(); i++){
        cout << v1[i] << " ";
        size++;
    }

    return;
}


int main(){
    node* root = nullptr;

    root = preOrderBuild();

    levelOrder(root);
    cout << endl;

    printPath(root, 3, 6);

    cout << endl << size-1 << endl;

    return 0;
}

// 10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1
// 4 2 1 -1 -1 3 -1 -1 5 7 -1 -1 6 -1 -1
