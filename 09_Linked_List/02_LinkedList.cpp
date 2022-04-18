#include <iostream>
#include "01_Node.cpp"
using namespace std;

// declarations
int size(node* head);
node* takeInput();

// INSERT METHODS

// insert the node at the head of the list.
void push_front(node*&head, int d){
    if(head == nullptr){
        head = new node(d);
        return;
    }

    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

// insert node at the tail of the list.
void push_back(node*&head, int d){
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

// insert node at a given position.
void push(node*&head, int d,int pos){
    if(head == nullptr or pos == 0){
        push_front(head, d);
        return;
    }
    else if(pos > size(head)){
        push_back(head, d);
    }
    else{
        int jump = 1;
        node* temp = head;

        while(jump <= pos-1){
            temp = temp->next;
            jump++;
        }

        node* n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }

    return;
}

// DELETE METHODS

// delete from the front of the list 
// return deleted node data
int pop_front(node*&head){
    if(head == nullptr)
        return -1;
    node* temp = head;
    head = head->next;
    int temp_data = temp->data;
    delete temp;
    return temp_data;
}

// delete node from the back of the list
// return deleted node data
void pop_back(node*&head){
    if(head == nullptr)
        return;
    else if(head->next == nullptr){
        node* temp = head;
        head = head->next;
        delete temp;
    }
    else{
        node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next->next;
        temp->next = nullptr;
    }
}

// UTILITY METHODS.

// return the length of the list.
int size(node* head){
    int len = -1;
    if(head == nullptr)
        return len;

    while(head != nullptr){
        len++;
        head = head->next;
    }
    return len;
}

// take continuous input until -1 is provided
node* takeInput(){
    int d; cin >> d;
    node* head = nullptr;
    while(d > 0){
        push_back(head, d);
        cin >> d;
    }
    return head;
}

// search in linked-list
// returns the index of the target node.
int search(node*head, int k){
    if(head == nullptr)
        return -1;
    int count = 0;
    while(head != nullptr){
        if(head->data == k)
            return count;
        count++;
        head = head->next;
    }
    return -1;
}

// print all linkedlist
void print(node* head){
    if(head == nullptr)
        return;

    cout << "HEAD -> ";
    while(head != nullptr){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
    return;
}

// OVERLOADED OPERATORS

// overloaded istream operators
istream& operator >> (istream& input_stream, node*&head){
    head = takeInput();
    return input_stream;
}

// overloaded ostream operators
ostream& operator << (ostream& output_stream, node*head){
    print(head);
    return output_stream;
}

// int main(){
//     node* head = nullptr;
//     // cin >> head;
//     push_back(head, 10);
//     push_back(head, 20);
//     push_back(head, 30);
//     push(head, 40, 1);

//     int r = search(head, 30);
//     cout << r << endl;
//     cout << head;

//     return 0;
// }
