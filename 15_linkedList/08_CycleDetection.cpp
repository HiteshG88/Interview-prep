// https://leetcode.com/problems/linked-list-cycle/

#include <bits/stdc++.h>
#include "02_LinkedList.cpp"
using namespace std;

bool isCycle(node* head){
    if(head == nullptr) return 0;
    node* f = head, *s = head;
    while(f && s && f->next){
        if(f == s) return 1;
        s = s->next;
        f = f->next->next;
    }
    return 0;
}

int main()
{
    node* head = nullptr;
    cin >> head;
    cout << isCycle(head);
    return 0;
}