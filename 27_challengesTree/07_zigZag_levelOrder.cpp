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

pair<int, bool> isBalanced(node *root){

    pair<int, bool> p;

    if(root == nullptr){
        p.first = 0;
        p.second = true;
        return p;
    }

    pair<int, bool> l = isBalanced(root->left);
    pair<int, bool> r = isBalanced(root->right);

    p.first = max(l.first, r.first) + 1;

    if(abs(l.first - r.first) < 2)
        p.second = true;
    else
        p.second = false;

    return p;
}

int main()
{
    node *root = build("true");

    levelOrder(root);

    return 0;
}















