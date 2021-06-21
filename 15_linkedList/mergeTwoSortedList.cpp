#include <iostream>
#include "linkedlist.cpp"
using namespace std;

node* merge(node*a, node*b){
    if(a == nullptr)
        return b;
    if(b == nullptr)
        return a;
    node* c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main(){
    node* a = nullptr;
    insertAtTail(a, 10);
    insertAtTail(a, 20);
    insertAtTail(a, 30);
    insertAtTail(a, 40);
    insertAtTail(a, 50);

    node* b = nullptr;
    insertAtTail(b, 11);
    insertAtTail(b, 21);
    insertAtTail(b, 31);
    insertAtTail(b, 41);
    insertAtTail(b, 51);

    node* c = merge(a,b);
    print(c);

    // cout << kthNodeEnd(head, 1);
    return 0;
}
