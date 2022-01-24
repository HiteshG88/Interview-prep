#include <iostream>
#include <stack>
using namespace std;

struct node{
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
void print(node* head){
    if(head == nullptr)
        return;

    while(head != nullptr){
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
    return;
}

bool palindrome(node* head){

    stack<int> s;

    node* h = head;
    while(h != nullptr){
        s.push(h->data);
        h = h->next;
    }

    node*temp = head;
    while(!s.empty()){

        // cout << s.top() << ", ";

        if(temp->data != s.top())
            return false;

        s.pop();
        temp = temp->next;
    }

    return true;
}


int main(){

    int n; cin >> n;
    node* head = nullptr;

    for(int i = 0; i < n; i++){
        int d; cin >> d;
        insertAtTail(head, d);
    }

    // print(head);

    if(palindrome(head))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
