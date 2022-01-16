// https://leetcode.com/problems/reorder-list/

#include <bits/stdc++.h>
#include "02_LinkedList.cpp"
using namespace std;


node* reverse(node* head){
    if(!head or !head->next) return head;
    node* c = head, *p = nullptr, *n = nullptr;
    while(c){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    return p;
}

node* midPoint(node* head){
    node *s = head, *f = head->next;
    while(f and f->next){
        s = s->next;
        f = f->next->next;
    }
    return s;
}

void reorderList(node*& head) {
    if(head == nullptr or head->next == nullptr) return;

    node* dummy = new node(-1);
    node* ans = dummy;

    // step1. find the mid point
    node* mid = midPoint(head);
    node* n = mid->next;
    mid->next = nullptr;
    // cout << "head: " << head << endl;

    // step2. reverse the second half
    node* revStart = reverse(n);
    // cout << "revStart: " << revStart << endl;

    // step3. take 1 node from both list acc. to make 1->n->2->n-2->3->n-3...
    while(revStart != nullptr){
        dummy->next = head;
        head = head->next;
        dummy->next->next = revStart;
        revStart = revStart->next;
        dummy = dummy->next->next;
    }

    if(head){
        dummy->next = head;
    }

    head = ans->next;
    return;
}


int main()
{
    node* head = nullptr;
    cin >> head;
    reorderList(head);
    cout << head;
    return 0;
}