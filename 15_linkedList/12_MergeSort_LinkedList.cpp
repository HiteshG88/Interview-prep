// https://leetcode.com/problems/sort-list/

#include <bits/stdc++.h>
#include "02_LinkedList.cpp"
using namespace std;

node* merge(node* l1, node* l2)
{
    node dump(0);
    node* cur = &dump;
    
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data < l2->data)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
            
        cur = cur->next;
    }
    
    if (l1 != NULL)
        cur->next = l1;
    else
        cur->next = l2;
        
    return dump.next;
}

node* sortList(node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    
    node* slow = head;
    node* fast = head->next;
    
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    //divide the list into two parts 
    fast = slow->next;
    slow->next = NULL;
    
    return merge(sortList(head), sortList(fast));
}


int main(){
    node* head;
    cin >> head;

    head = sortList(head);
    cout << head;

    return 0;
}

/*

node* midpointList(node*head){
    if(head == nullptr or head->next == nullptr)
        return head;
    node* s = head, *f = head->next;

    while(f != nullptr and f->next != nullptr){
        f = f->next->next;
        s = s->next;
    }
    return s;
}

node* merge(node*a, node*b){
    if(a == nullptr)
        return b;
    if(b == nullptr)
        return a;
    node* c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node* mergeSortList(node*head){
    if(head == nullptr or head->next == nullptr)
        return head;

    node* mid = midpointList(head);
    node* a = head;
    node* b = mid->next;
    mid->next = nullptr;

    a = mergeSortList(a);
    b = mergeSortList(b);

    node* c = merge(a,b);
    return c;
}


int main(){
    node* head;
    cin >> head;

    head = mergeSortList(head);
    cout << head;

    return 0;
}


*/ 