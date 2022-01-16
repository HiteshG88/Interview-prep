#include <bits/stdc++.h>
#include "02_LinkedList.cpp"
using namespace std;

void reverseLinkedList(node*& head){
    if(!head) return;
    node *curr = head, *next = nullptr, *prev = nullptr;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return;
}

node* reverseRecursive(node*& head){
    if(!head or !head->next){
        return head;
    }
    node* new_head = reverseRecursive(head->next);
    
    // make the next element of the last called head point to itself.
    // this will change the order of the list.
    head->next->next = head;
    
    // make the head point to null as it could be the last node.
    head->next = nullptr;

    return new_head;
}

int main()
{
    node* head = nullptr;
    cin >> head;
    head = reverseRecursive(head);
    cout << head;
    return 0;
}