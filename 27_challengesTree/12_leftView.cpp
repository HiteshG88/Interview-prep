#include <iostream>
#include <queue>
using namespace std;

class node{
public:
    int data;
    node* right, *left;
    node(int d){
        data = d;
        right = left = nullptr;
    }
};

node* createTree(node* root){

    int d; cin >> d;
    root = new node(d);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){

        node* t = q.front();
        q.pop();
        int c1, c2; cin >> c1 >> c2;

        if(c1 != -1){
            t->left = new node(c1);
            q.push(t->left);
        }
        if(c2 != -1){
            t->right = new node(c2);
            q.push(t->right);
        }
    }
    return root;
}

void leftViewHandler(node* root, int level, int &max_level){

    if(root == nullptr)
        return;

    if(level > max_level){
        cout << root->data << " ";
        max_level = level;
    }

    leftViewHandler(root->left, level+1, max_level);
    leftViewHandler(root->right, level+1, max_level);
}

void leftView(node* root){
    int max_level = -1;
    leftViewHandler(root, 0, max_level);
    return;
}

void preOrder(node* root){
    if(root == nullptr)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){

    node* root = nullptr;
    root = createTree(root);

    leftView(root);

    return 0;
}
