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

    if(isBalanced(root).second)
        cout << "true";
    else
        cout << "false";

    return 0;
}
