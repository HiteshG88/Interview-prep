#include <iostream>
#include <algorithm>
#include "bst.cpp"
using namespace std;

node* treeFromTrav(int pre[], int in[], int s, int e){

    // static beacuse we need same of i for every call.
    static int i = 0;

    if(s>e)
        return nullptr;

    // the first node in pre[] is always the node
    node* root = new node(pre[i]);

    // linear search for index in in[]
    int index = -1;
    for(int j = s; j <= e; j++){
        if(in[j] == pre[i]){
            index = j;
            break;
        }
    }

    // increament i for the next call
    i++;

    // recursive calls -> (only change will be in starting and endings)
    root->left = treeFromTrav(pre, in, s, index-1);
    root->right = treeFromTrav(pre, in, index+1, e);

    return root;
}

node* BstFromPreOrder(int pre[], int size){

    int in[size];
    for(int i = 0; i < size; i++)
        in[i] = pre[i];

    sort(in,in+size);

    node* result = treeFromTrav(pre,in,0,size-1);

    return result;
}

int main(){

    int pre[] = {5,3,1,7,6,8};
    int n = sizeof(pre)/sizeof(int);

    node* root =  BstFromPreOrder(pre,n);

    bfs(root);
    cout << endl;

    return 0;
}
