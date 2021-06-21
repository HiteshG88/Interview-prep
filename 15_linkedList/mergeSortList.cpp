#include <iostream>
#include "linkedlist.cpp"
using namespace std;

node* midpointList(node*head){
    if(head == nullptr or head->next == nullptr)
        return head;
    node* s = head, *f = head->next;

    while(f != nullptr and f->next != nullptr){
        f = f->next->next;
        s = s->next;
    }
    return s;
}

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

node* mergeSortList(node*head){
    if(head == nullptr or head->next == nullptr)
        return head;

    node* mid = midpointList(head);
    node* a = head;
    node* b = mid->next;
    mid->next = nullptr;

    a = mergeSortList(a);
    b = mergeSortList(b);

    node* c = merge(a,b);
    return c;
}


int main(){
    node* head;
    cin >> head;

    head = mergeSortList(head);
    cout << head;

    return 0;
}
