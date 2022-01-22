// https://leetcode.com/problems/rotate-list/

#include <bits/stdc++.h>
#include "02_LinkedList.cpp"
using namespace std;

node* rotateRight(node* head, int k) {
    if(k <= 0 or !head or !head->next){
        return head;
    }

    int length = 1;
    node* last = head;
    while(last->next != nullptr){
        last = last->next;
        length++;
    }

    last->next = head;
    int rotation = k%length;
    int skip = length-rotation;
    node* new_end = head;

    while(skip-1){
        new_end = new_end->next;
        skip--;
    }

    head = new_end->next;
    new_end->next = nullptr;

    return head;
}

int main()
{
    node* head = nullptr;
    cin >> head;
    head = rotateRight(head, 2);
    cout << head;
    return 0;
}