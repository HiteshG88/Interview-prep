// https://leetcode.com/problems/reverse-linked-list-ii/

#include <bits/stdc++.h>
#include "02_LinkedList.cpp"
using namespace std;

node* reverseBetween(node* head, int left, int right) {
    if(left == right) return head;

    node* curr = head, *prev = nullptr;

    // Move the current pointer left - 1 paces ahead.
    for (int i = 0; curr != NULL && i < left-1; i++){
        prev = curr;
        curr = curr->next;
    }
    
    node* last = prev, *new_end = curr, *next = nullptr;

    for(int i = 0; curr != nullptr and i < right-left+1; i++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    if(last != nullptr){
        last->next = prev;
    }else{
        head = prev;
    }
    new_end->next = curr;

    return head;
}

int main()
{
    node* head = nullptr;
    cin >> head;
    head = reverseBetween(head, 2, 4);
    cout << head;
    return 0;
}