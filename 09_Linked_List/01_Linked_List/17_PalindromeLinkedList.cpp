// https://leetcode.com/problems/palindrome-linked-list/submissions/

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

bool isPalindrome(node* head) {
    if(head == nullptr or head->next == nullptr) return true;

    // step1. find the mid point of the list
    node* mid = midPoint(head);
    cout << "mid: " << mid->data << endl;

    // step2. reverse the 2nd half os the list
    node* revStart = reverse(mid->next);
    cout << "revStart: " << revStart->data << endl;
    // cout << revStart << endl;

    // step3. take two pointer, one at start another at mid, and check all node are equal.
    while(revStart){
        if(head->data != revStart->data) return false;
        head = head->next;
        revStart = revStart->next;
    }
    return true;
}

int main()
{
    node* head = nullptr;
    cin >> head;
    cout << isPalindrome(head) << endl;
    // cout << head;
    return 0;
}