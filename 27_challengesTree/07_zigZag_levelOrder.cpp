#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}


void levelOrder(node* root){

    if(root == nullptr)
        return;

    // make a queue of pair of node* and level(int)
    queue< pair<node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){

        pair<node*, int> temp = q.front();

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


int main()
{
    node *root = build("true");

    levelOrder(root);

    return 0;
}















