// find the starting point of the cycle present in the linked list.
// https://leetcode.com/problems/linked-list-cycle-ii/submissions/

#include <bits/stdc++.h>
#include "02_LinkedList.cpp"
using namespace std;

node* StartOfCycle(node* head){
    if(head == nullptr) return 0;
    node* f = head, *s = head;
    while(f && s && f->next){
        s = s->next;
        f = f->next->next;
        if(f == s){
            // 1. take fast pointer at the head of the list.
            // 2. dont change the position of slow pointer.
            // 3. move both pointer at 1 node at a time, until the meet, 
            // 4. their meeting point is the start of the cycle.
            f = head;
            while(s != f){
                f = f->next;
                s = s->next;
            }
            return s;
        }
    }

    return nullptr;
}

int main()
{
    
    return 0;
}