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

// utility function for length of linked list.
int length(node* head){
    int len = -1;
    if(head == nullptr)
        return len;

    while(head != nullptr){
        len++;
        head = head->next;
    }
    return len;
}


// insert functions
void insertAtHead(node*&head, int d){
    if(head == nullptr){
        head = new node(d);
        return;
    }

    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

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

void insertAtMiddle(node*&head, int d,int pos){
    if(head == nullptr or pos == 0){
        insertAtHead(head, d);
        return;
    }
    else if(pos > length(head)){
        insertAtTail(head, d);
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

node* takeInput(){
    int d; cin >> d;
    node* head = nullptr;
    while(d > 0){
        insertAtTail(head, d);
        cin >> d;
    }
    return head;
}


// delete functions
void deleteFromHead(node*&head){
    if(head == nullptr)
        return;
    node* temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteFromTail(node*&head){
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


// search in linked-list
bool searchList(node*head, int k){
    if(head == nullptr)
        return false;
    while(head != nullptr){
        if(head->data == k)
            return true;
        head = head->next;
    }
    return false;
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

// overloaded operators
istream& operator >> (istream& is, node*&head){
    head = takeInput();
    return is;
}
ostream& operator << (ostream& os, node*head){
    print(head);
    return os;
}

// int main(){
//     node* head;
//     cin >> head;
//     // insertAtTail(head, 10);
//     // insertAtTail(head, 20);
//     // insertAtTail(head, 30);
//     // insertAtMiddle(head, 40, 1);

//     bool r = searchList(head, 3);
//     cout << head;
//     cout << r;

//     return 0;
// }
