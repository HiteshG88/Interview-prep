#include <iostream>
#include "treeBasic.cpp"
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

int main(){

    int in[] = {3,2,8,4,1,6,7,5};
    int pre[] = {1,2,3,4,8,5,6,7};
    int n = sizeof(in)/sizeof(int);

    node* root =  treeFromTrav(pre, in, 0, n-1);

    levelOrder(root);
    cout << endl;

    return 0;
}
