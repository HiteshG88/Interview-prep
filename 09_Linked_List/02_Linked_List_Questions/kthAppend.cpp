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


node* kthAppend(node* head, int k){
    if(head == nullptr or head->next == nullptr)
        return head;

    node* s = head, *f =head;
    while(k>0){
        f = f->next;
        k--;
    }

    while(f->next != nullptr){
        f = f->next;
        s = s->next;
    }

    f->next = head;
    head = s->next;
    s->next = nullptr;

    return head;
}


int main(){

    int n; cin >> n;
    node* head = nullptr;
    head = buildList(head, n);
    int k; cin >> k;

    head = kthAppend(head, k);

    print(head);
}
