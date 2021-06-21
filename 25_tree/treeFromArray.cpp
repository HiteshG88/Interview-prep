#include <iostream>
#include "treeBasic.cpp"
using namespace std;

node* arrayTree(int a[], int s, int e){

    if(s>e)
        return nullptr;

    int mid = (s+e)/2;

    node* root = new node(a[mid]);

    root->left = arrayTree(a, s, mid-1);
    root->right = arrayTree(a, mid+1, e);

    return root;
}

int main(){

    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(int);

    node* root =  arrayTree(arr, 0, n-1);

    levelOrder(root);
    cout << endl;

    return 0;
}
