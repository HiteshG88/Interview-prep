#include <iostream>
using namespace std;

class node{
public:
    node* right, *left;
    int data;

    node(int d){
        right = left = nullptr;
        data = d;
    }
};

node* buildTreeGeneric(node*root){
    int d,n ;
    cin >> d >> n;
    root = new node(d);
    if(n==0){
        return root ;
    }
    else if(n==1){
        root->left = buildTreeGeneric(root->left);
        return root ;
    }
    else {
        root->left = buildTreeGeneric(root->left);
        root->right = buildTreeGeneric(root->right) ;
        return root ;
    }
}

int SumAtK(node* root, int k, int &sum){

    if(root == nullptr)
        return sum;

    if(k == 0)
        sum += root->data;

    SumAtK(root->left, k-1, sum);
    SumAtK(root->right, k-1, sum);

    return sum;
}


int main(){

    node* root = nullptr;
    root = buildTreeGeneric(root);

    int k; cin >> k;

    int s = 0;
    cout << SumAtK(root, k, s);

    return 0;
}

