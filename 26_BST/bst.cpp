// #include <iostream>
#include <queue>
#include <climits>
using namespace std;

class node{
public:
    int data;
    node* left, *right;

    node(int d){
        data = d;
        left = right = nullptr;
    }
};

/* fuctions */
node* insert(node*, int);
node* build(node*);
void bfs(node*);
node* search(node*, int);
node* deleteInBST(node*,int);

bool isBST(node* root, int min = INT_MIN, int max = INT_MAX){

    if(root == nullptr)
        return true;

    int curr = root->data;
    if(curr >= min and curr <= max and isBST(root->left, min, root->data) and isBST(root->right, root->data, max))
        return true;

    return false;
}

// int main(){

//     node* root = nullptr;

//     root = build(root);

//     deleteInBST(root, 5);

//     bfs(root);

//     cout << isBST(root);

//     return 0;
// }

// 5 3 1 7 6 8 -1


node* insert(node* root, int data){

    if(root == nullptr){
        return new node(data);
    }

    int curr = root->data;

    if(data > curr)
        root->right = insert(root->right, data);
    else
        root->left = insert(root->left, data);

    return root;
}

node* build(node* root){
    int d; cin >> d;

    while(d != -1){
        root = insert(root, d);
        cin >> d;
    }
    return root;
}

void bfs(node* root){

    if(root == nullptr)
        return;

    queue<node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){

        node* temp = q.front();

        // for handling line change
        if(temp == nullptr){
            cout << endl;
            q.pop();

            if(!q.empty())
                q.push(nullptr);
        }
        else{
            q.pop();

            cout << temp->data << ", ";

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

node* search(node* root, int key){

    if(root == nullptr)
        return root;

    if(root->data == key)
        return root;

    if(key <= root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

node* deleteInBST(node* root, int k){

    if(root == nullptr)
        return nullptr;

    // traverse inOrderly to find the key
    if(k < root->data){
        root->left = deleteInBST(root->left, k);
        return root;
    }
    else if(k == root->data){
        // three cases:
        // 1. if there is no child of to be deleted node.
        if(root->left == nullptr and root->right == nullptr){
            delete root;
            return nullptr;
        }

        // 2. if there is one child.
        if(root->left != nullptr and root->right == nullptr){
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == nullptr and root->right != nullptr){
            node* temp = root->right;
            delete root;
            return temp;
        }

        // 3. if there are 2 childrens:
        node* replace = root->right;

        while(replace->left != nullptr)
            replace = replace->left;

        // copy the data of inorder successor of root into root->data
        root->data = replace->data;

        // delete the replace node
        root->right = deleteInBST(root->right, replace->data);
    }
    else{
        root->right = deleteInBST(root->right, k);
        return root;
    }
    return root;
}

