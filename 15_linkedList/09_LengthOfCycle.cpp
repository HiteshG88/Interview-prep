// Find the length of the cycle in linked list.
// given: Linked List with a Cycle

#include <bits/stdc++.h>
#include "02_LinkedList.cpp"
using namespace std;

int LengthCycle(node* head){
    if(head == nullptr) return 0;
    node* f = head, *s = head;
    while(f && s && f->next){
        s = s->next;
        f = f->next->next;
        if(f == s) break;
    }
    // After finding the Cycle in linked list, stop the f pointer on its place and only increment the slow pointer till the meet again, while keeping a counter to count the steps slow pointer takes.
    int count = 1;
    s = s->next;
    while(s != f){
        count++;
        s = s->next;
    }
    return count;
}

int main()
{
    node* head = nullptr;
    // ! not yet completed the main method part...
    cout << LengthCycle(head);
    return 0;
}