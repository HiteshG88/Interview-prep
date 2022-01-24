#include <iostream>
#include "02_LinkedList.cpp"
using namespace std;

node* midpointList(node* head){
    if(head == nullptr or head->next == nullptr)
        return head;
    node* s = head, *f = head->next;

    while(f != nullptr and f->next != nullptr){
        f = f->next->next;
        s = s->next;
    }
    return s;
}

int main(){
    node* head;
    cin >> head;

    node* mid = midpointList(head);
    cout << head << mid;

    return 0;
}
