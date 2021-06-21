#include <iostream>
#include "linkedlist.cpp"
using namespace std;

int kthNodeEnd(node*&head, int k){
    node* slow = head, *fast = head;
    while(k--){
        fast = fast->next;
    }
    while(fast != nullptr){
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}

int main(){
    node* head = nullptr;
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);
    print(head);

    cout << kthNodeEnd(head, 1);
}
