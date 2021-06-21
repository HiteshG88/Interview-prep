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

node* buildList(node*head, int n){
    if(n == 0)
        return head;
    while(n--){
        int data;
        cin >> data;
        insertAtTail(head, data);
    }
    return head;
}

// print all linkedlist
void print(node*head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    print(head->next);
}


node* evenOdd(node*head){
    if(head == nullptr or head->next == nullptr)
        return head;

    node *o = nullptr,*e = nullptr, *i = head;
    node* es = nullptr;
    node* os = nullptr;

    while(i != NULL){
        int val = i -> data;

        // If current value is even, add
        // it to even values list.
        if(val % 2 == 0) {
            if(es == NULL){
                es = i;
                e = es;
            }

            else{
                e -> next = i;
                e = e -> next;
            }
        }

        // If current value is odd, add
        // it to odd values list.
        else{
            if(os == NULL){
                os = i;
                o = os;
            }
            else{
                o -> next = i;
                o = o -> next;
            }
        }

        // Move head pointer one step in
        // forward direction
        i = i -> next;
    }

    if(os == NULL || es == NULL){
        return nullptr;
    }

    // Add odd list after even list.
    o -> next = es;
    e -> next = NULL;

    // Modify head pointer to
    // starting of even list.
    return os;
}


int main(){

    int n; cin >> n;
    node* head = nullptr;
    head = buildList(head, n);

    head = evenOdd(head);

    print(head);
}
