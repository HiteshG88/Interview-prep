#include <iostream>
#include <vector>
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

void preOrder(node* root){
    // base case:
    if(root == nullptr)
        return;

    cout << root->data << " ";

    // recursive case:
    preOrder(root->left);
    preOrder(root->right);

    return;
}

node* insert(node* root, int data){

    if(root == nullptr)
        return new node(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

bool nodePath(node* root, int k, vector<int>& v){

    if(root == nullptr)
        return false;

    v.push_back(root->data);

    if(root->data == k)
        return true;

    // if any of the root node contain key return true
    if(nodePath(root->left, k, v) or nodePath(root->right, k, v))
        return true;

    // if key is not present both left and right of root the pop that root from v, and return false
    v.pop_back();
    return false;
}

void printPath(node* root, int k1, int k2){

    vector<int> v1;
    vector<int> v2;

    int i;

    if(nodePath(root, k1, v1) and nodePath(root, k2, v2)){

        for(i = 0; i < max(v1.size(), v2.size()); i++)
            if(v1[i] == v2[i]) break;
    }

    for(int j = v1.size()-1; j > i; j--)
        cout << v1[j] << " ";

    for(int j = i; j < v2.size(); j++)
        cout << v2[j] << " ";

    return;
}


int main(){

    int t; cin >> t;
    while(t--){

        node* root = nullptr;
        int n; cin >> n;

        for(int i = 0; i < n; i++){
            int data; cin >> data;
            root = insert(root, data);
        }

        int k1, k2; cin >> k1 >> k2;

        cout << "# Preorder : ";
        preOrder(root);
        cout << endl << "# Nodes within range are : ";
        printPath(root, k1, k2);

        // cout << endl;
    }

    return 0;
}


/*====================================
=            coding block            =
====================================

#include<iostream>
#include<algorithm>
using namespace std;

class node{

public:

    int data;
    node*right;
    node*left;

    node(int d){

        data=d;
        left=NULL;
        right=NULL;

    }

};

void preorder(node*root){


    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";


    preorder(root->left);
    preorder(root->right);

    return;

}


void PrintRange(node* root,int a,int b){

    if(root==NULL){
        return;
    }

    PrintRange(root->left,a,b);
    if(root->data<=b and root->data>=a){
        cout<<root->data<<" ";
    }
    PrintRange(root->right,a,b);
    return;

}

node* insert(node* root, int value){
    if(root==NULL){
        node *nn = new node(value);
        return nn;
    }
    if(value>root->data){
        root->right=insert(root->right, value);
    }else if(value<root->data){
        root->left=insert(root->left, value);
    }
    return root;
}

node* ArrToBST(int* arr, node* root, int n){
    for(int i=0; i<n; i++){
        root = insert(root,arr[i]);
    }
    return root;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];


        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        node* root=new node(arr[0]);
        root = ArrToBST(arr,root,n);
         int b,c;
         cin>>b>>c;

        cout<<"# Preorder : ";
        preorder(root);
        cout<<endl<<"# Nodes within range are : ";
        PrintRange(root,b,c);
        cout<<endl;

    }

}

/*=====  End of coding block  ======*/
