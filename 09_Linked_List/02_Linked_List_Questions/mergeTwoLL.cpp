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


void insertAtTail(node*&head, int d){
    if(head == nullptr){
        head = new node(d);
        return;
    }

    node* head_ref = head;
    while(head_ref->next != nullptr){
        head_ref = head_ref->next;
    }
    head_ref->next = new node(d);

    return;
}

// print all linkedlist
void print(node*head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    print(head->next);
}

node* merge(node* a, node* b){
    if(a == nullptr)
        return b;
    if(b == nullptr)
        return a;

    node* c= nullptr;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main(){
    int t; cin >> t;
    while(t--){

        int n; cin >> n;
        node* head1 = nullptr;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            insertAtTail(head1, x);
        }

        int n2; cin >> n2;
        node* head2 = nullptr;
        for(int i = 0; i < n2; i++){
            int x; cin >> x;
            insertAtTail(head2, x);
        }

        node* head = merge(head1, head2);
        print(head);
    }

}
