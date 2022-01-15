#include <iostream>
#include "02_LinkedList.cpp"
using namespace std;

node* helper(node*& head, int data){
    if(head == nullptr){
        return new node(data);
    }
    head->next = helper(head->next, data);
    return head;
}

void recursiveInsertion(node*& head, int data){
    node* temp = head;
    head = helper(temp, data);
    return;
}


node* takeInput_2(node* head){
    int input; cin >> input;
    while(input > -1){
        recursiveInsertion(head, input);
        cin >> input;
    }
    return head;
}

int main(){
    node* head = nullptr;
    head = takeInput_2(head);
    print(head);
    return 0;
}