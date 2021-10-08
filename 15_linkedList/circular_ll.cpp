#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node(int d){
        data = d;
        next = nullptr;
    }
};

// insert at head
void insert(node*&head, int data){

    node* n = new node(data);
    node* t = head;

    n->next = head;
    if(t != nullptr){
        while(t->next != head){
            t = t->next;
        }
        t->next = n;
    }
    else{
        // in the case there is no node in the list
        n->next = n;
    }

    head= n;
}

// print all linkedlist
void print(node* head){
    if(head == nullptr)
        return;

    node* temp = head;
    while(temp->next != head){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << "->";
    return;
}

int main(){

    node* head = nullptr;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);
    insert(head, 60);
    insert(head, 70);

    print(head);

    return 0;
}
