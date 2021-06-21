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

int daimeter(node* root){
    if(root == nullptr)
        return 0;

    int left_h = height(root->left);
    int right_h = height(root->right);

    int opt1 = left_h + right_h;
    int opt2 = daimeter(root->left);
    int opt3 = daimeter(root->right);

    return max(opt1, max(opt2, opt3));
}

pair<int,int> diameter_optimized(node* root){

    pair<int, int> p;

    if(root == nullptr){
        p.first = p.second = 0;   // first = height, second = daimeter
        return p;
    }

    pair<int, int> left = diameter_optimized(root->left);
    pair<int, int> right = diameter_optimized(root->right);

    p.first = max(left.first, right.first) + 1;

    p.second = max(left.first + right.first, max(left.second, right.second));

    return p;
}

int main(){

    node* root = preOrderBuild();

    levelOrder(root);

    pair<int, int> r =  diameter_optimized(root);

    cout << "h: " << r.first << " d: " << r.second << endl;
    // cout << countNodes(root) << endl;
    // cout << sumNodes(root) << endl;

    return 0;
}

// 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
