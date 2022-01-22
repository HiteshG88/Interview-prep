// https://leetcode.com/problems/reverse-nodes-in-k-group/

#include <bits/stdc++.h>
#include "02_LinkedList.cpp"
using namespace std;

int getSize(node* head){
    int len = 0;
    while(head != nullptr){
        head = head->next;
        len++;
    }
    return len;
}

node* KthGrpReverse(node* head, int k) {
    if(k <= 1) return head;

    node* curr = head, *prev = nullptr;

    int len = getSize(head);
    int count = len/k;
    while(count){
        
        node* last = prev, *new_end = curr, *next = curr->next;

        for(int i = 0; curr != nullptr && i < k; i++){
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next != nullptr){
                next = next->next;
            }
        }

        if(last != nullptr){
            last->next = prev;
        }else{
            head = prev;
        }
        new_end->next = curr;

        if(curr == nullptr){
            break;
        }

        prev = new_end;
        count--;
    }
    return head;
}

int main()
{
    node* head = nullptr;
    cin >> head;
    head = KthGrpReverse(head, 3);
    cout << head;
    return 0;
}