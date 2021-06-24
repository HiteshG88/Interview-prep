#include <iostream>
#include "bst.cpp"
using namespace std;

class linkedList{
public:
    node* head;
    node* tail;
    linkedList(){
        head = tail = nullptr;
    }
};

linkedList flattenBST(node* root){

    linkedList l;

    if(root == nullptr)
        return l;

    // there can be 4 cases for this algo:
    // 1. there is no child:
    if(root->left == nullptr and root->right == nullptr){
        l.head = l.tail = root;
        return l;
    }

    // 2. there is only left size
    if(root->left != nullptr and root->right == nullptr){

        // get a linkedList from left side:
        linkedList leftLL = flattenBST(root->left);
        leftLL.tail->right = root;

        // update the returning list l
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }

    // 3. there is only right side:
    if(root->right != nullptr and root->left == nullptr){
        // get the linkedList from right side
        linkedList rightLL = flattenBST(root->right);
        root->right = rightLL.head;

        // upadte the returning list l
        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }

    // 4. there is left as well as right side (insertion of root in middle):
    linkedList leftLL = flattenBST(root->left);
    linkedList rightLL = flattenBST(root->right);

    // combine the left and right list came from left and right tree:
    leftLL.tail->right = root;
    root->right = rightLL.head;

    // update the the list l:
    l.head = leftLL.head;
    l.tail = rightLL.tail;

    return l;
}


int main(){

    node* root = nullptr;
    root = build(root);

    bfs(root);
    cout << endl;

    linkedList l = flattenBST(root);
    node* temp = l.head;

    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->right;
    }

    return 0;
}

// 5 3 1 7 6 8 -1
