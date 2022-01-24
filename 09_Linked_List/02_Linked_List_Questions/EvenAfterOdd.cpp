#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = nullptr;
    }
};

node* buildList(node* head, int n){
    while(n--){
        int d; cin >> d;
        node* n = new node(d);
        n->next = head;
        head = n;
    }
    return head;
}

void printList(node* head){
    while(head != nullptr){
        cout << head->data << "->";
        head = head->next;
    }
}

node* EvenOddSort(node* head){
    node* e = nullptr;

    while(head != nullptr){
        
    }
}

int main(){

    int n; cin >> n;
    node* head = nullptr;

    head = buildList(head, n);
    printList(head);

    return 0;
}
