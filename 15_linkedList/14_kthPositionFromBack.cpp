#include <iostream>
#include "02_LinkedList.cpp"
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
    push_back(head, 10);
    push_back(head, 20);
    push_back(head, 30);
    push_back(head, 40);
    push_back(head, 50);
    print(head);

    cout << kthNodeEnd(head, 3) << endl;
}
