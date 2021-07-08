#include <iostream>
#include <queue>
#include <map>
#include <vector>

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

void verticalPrint(node* root, int d, map<int, vector<int>> &m){
    if(root == nullptr)
        return;

    // add the root->data in the corrosponding distance(d) bucket
    m[d].push_back(root->data);

    verticalPrint(root->left, d-1, m);
    verticalPrint(root->right, d+1, m);
    return;
}



int main(){

    node* root = preOrderBuild();

    levelOrder(root);
    cout << endl;

    map<int, vector<int>> m;
    verticalPrint(root, 0, m);

    for(auto val : m){
        cout << val.first << ": ";
        for(auto v : val.second)
            cout << v << ", ";
        cout << endl;
    }

    return 0;
}

// 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
