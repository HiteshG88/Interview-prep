#include <iostream>
#include "02_LinkedList.cpp"
using namespace std;

void removeDuplicates(node*& head){
    if(head == nullptr) return;
    node* temp = head;
    while(temp != nullptr && temp->next != nullptr){
        if(temp->data != temp->next->data){
            temp = temp->next;
            continue;
        }
        temp->next = temp->next->next;
    }
    return;
}


int main(){

    node* head = nullptr;
    cin >> head;

    removeDuplicates(head);

    cout << head;

}