#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = nullptr;
    }
};


void insertAtTail(node*&head, int d){
    if(head == nullptr){
        head = new node(d);
        return;
    }

    node* head_ref = head;
    while(head_ref->next != nullptr){
        head_ref = head_ref->next;
    }
    head_ref->next = new node(d);

    return;
}

// print all linkedlist
void print(node*head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    print(head->next);
}

node* kthReverse(node*& head, int k){
    // base case
    if (head == nullptr)
        return nullptr;

    node* p= nullptr, *c = head, *n=nullptr;
    int count = 0;

    while(c != nullptr and count < k){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
        count++;
    }
    if(n != nullptr)
        head->next = kthReverse(n,k);

    return p;
}

int main(){
    int n,k; cin >> n >> k;
    node* head = nullptr;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        insertAtTail(head, x);
    }
    head = kthReverse(head, k);
    print(head);
}
