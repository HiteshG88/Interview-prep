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

void rightViewHandler(node* root, int level, int &max_level){

    if(root == nullptr)
        return;

    if(level > max_level){
        cout << root->data << endl;
        max_level = level;
    }

    rightViewHandler(root->right, level+1, max_level);
    rightViewHandler(root->left, level+1, max_level);
}

void leftViewHandler(node* root, int level, int &max_level){

    if(root == nullptr)
        return;

    if(level > max_level){
        cout << root->data << endl;
        max_level = level;
    }

    leftViewHandler(root->left, level+1, max_level);
    leftViewHandler(root->right, level+1, max_level);
}

void rightView(node* root){
    int max_level = -1;
    rightViewHandler(root, 0, max_level);
}

void leftView(node* root){
    int max_level = -1;
    leftViewHandler(root, 0, max_level);
}

int main(){

    int pre[] = {1,2,3,4,8,5,6};
    int n = sizeof(pre)/sizeof(int);

    node* root =  arrayTree(pre, 0, n-1);

    levelOrder(root);
    cout << endl;
    rightView(root);
    cout << endl;
    leftView(root);
    cout << endl;

    return 0;
}
