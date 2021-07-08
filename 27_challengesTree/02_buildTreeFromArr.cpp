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

node* BuildTreeArr(int arr[], int s, int e){

    if(s>e)
        return nullptr;

    int mid = (s+e)/2;

    node* root = new node(arr[mid]);

    root->left = BuildTreeArr(arr, s, mid-1);
    root->right = BuildTreeArr(arr, mid+1, e);

    return root;
}

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

int main(){

    int t; cin >> t;
    while(t--){

        // size of the array:
        int n; cin >> n;
        int arr[n];

        for(int i = 0; i < n; i++)
            cin >> arr[i];

        node* root = nullptr;
        root = BuildTreeArr(arr, 0, n-1);

        preOrder(root);
        cout << endl;
    }

    return 0;
}
