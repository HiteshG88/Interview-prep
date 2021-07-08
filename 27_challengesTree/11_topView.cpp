#include <iostream>
#include <queue>
#include <map>
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

node* createTree(node* root){
    int d;
    cin>>d;

    root = new node(d);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){

        node*f = q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;

        if(c1!=-1){
            f->left = new node(c1);
            q.push(f->left);
        }
        if(c2!=-1){
            f->right = new node(c2);
            q.push(f->right);
        }
    }
 return root;
}

void topView(node* root){

    if(root == nullptr)
        return;

    map<int, int> m;

    // first = data, second = height
    queue< pair<node*, int> > q;
    q.push({root, 0});

    while(!q.empty()){

        node* temp = q.front().first;
        int h = q.front().second;

        q.pop();

        // if map doesn't have a value set at given height,
        // this is the first time that node is visited
        if(!m[h])
            m[h] = temp->data;

        // traverse the rest of the tree
        // increase height if goes right, and decrease when goes left
        if(temp->left)
            q.push({temp->left,h-1});
        if(temp->right)
            q.push({temp->right,h+1});
    }

    for(auto val : m)
        cout << val.second << " ";
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

    // preOrder(root);

    topView(root);

    return 0;
}

