#include <bits/stdc++.h>
#include "02_LinkedList.cpp"
using namespace std;

node* merge_rec(node*a, node*b){
    if(a == nullptr)
        return b;
    if(b == nullptr)
        return a;
    node* c;
    if(a->data < b->data){
        c = a;
        c->next = merge_rec(a->next, b);
    }
    else{
        c = b;
        c->next = merge_rec(a, b->next);
    }
    return c;
}

node* mergeList(node* h1, node* h2){
    if(h1 == nullptr) return h2;
    if(h2 == nullptr) return h1;
    node* a = new node(-1);
    node* ans = a;
    while(h1 && h2){
        if(h1->data < h2->data){
            ans->next = h1;
            h1 = h1->next;
        }else{
            ans->next = h2;
            h2 = h2->next; 
        }
        ans = ans->next;
    }
    while(h1){
        ans->next = h1;
        h1 = h1->next;
    }
    while(h2){
        ans->next = h2;
        h2 = h2->next;
    }
    return a->next;
}

int main()
{
    node* head1 = nullptr;
    node* head2 = nullptr;
    cin >> head1;
    cin >> head2;
    head1 = mergeList(head1, head2);
    cout << head1;
    return 0;
}