#include <iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    node* right;
    node* left;

    node(int d){
        data = d;
        right = left = nullptr;
    }
};

node* preOrderBuild(){

    int data; cin >> data;

    if(data == -1)
        return nullptr;

    node* root = new node(data);

    root->left = preOrderBuild();
    root->right = preOrderBuild();

    return root;
}

void preOrder(node* root){
    if(root == nullptr)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){
    if(root == nullptr)
        return;

    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
}

void inOrder(node* root){
    if(root == nullptr)
        return;

    preOrder(root->left);
    cout << root->data << " ";
    preOrder(root->right);
}

int height(node* root){
    if(root == nullptr)
        return 0;

    int h = max(height(root->left), height(root->right)) + 1;
    return h;
}

void levelOrder(node* root){

    if(root == nullptr)
        return;

    queue<node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){

        node* temp = q.front();

        if(temp == nullptr){
            cout << endl;
            q.pop();

            if(!q.empty())
                q.push(nullptr);
        }
        else{
            q.pop();

            cout << temp->data << " ";

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

void printLevel(node* root, int k){

    if(root == nullptr)
        return;

    if(k == 1)
        cout << root->data << " ";

    printLevel(root->left, k-1);
    printLevel(root->right, k-1);
}

void levelOrder_rec(node* root){

    if(root == nullptr)
        return;

    int h = height(root);

    for(int i = 0; i <= h; i++){
        printLevel(root, i);
        cout << endl;
    }

}

int countNodes(node* root){

    if(root == nullptr)
        return 0;

    int lc = countNodes(root->left);
    int rc = countNodes(root->right);

    return 1+lc+rc;
}

int sumNodes(node* root){
    if(root == nullptr)
        return 0;

    int sum = sumNodes(root->left) + sumNodes(root->right) + root->data;

    return sum;
}

int main(){

    node* root = preOrderBuild();
    // preOrder(root);
    // cout << endl;
    // postOrder(root);
    // cout << endl;
    levelOrder(root);

    cout << endl;

    // cout << countNodes(root) << endl;
    cout << sumNodes(root) << endl;

    return 0;
}

// 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
