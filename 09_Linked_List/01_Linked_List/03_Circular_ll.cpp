#include <iostream>
#include "01_Node.cpp"
using namespace std;

class CircularList{
private:
    node* head;
    node* tail;
    int SIZE;

public:
    CircularList(){
        head = tail = nullptr;
        SIZE = 0;
    }

    void push_front(int data){
        if(this->head == nullptr){
            this->head = new node(data);
            this->tail = this->head;
            return;
        }
        node* new_node = new node(data);
        new_node->next = this->head;
        this->head = new_node;
        return;
    }

    void push_back(int data){
        if(head == nullptr){
            push_front(data);
            return;
        }
        node* new_node = new node(data);
        tail->next = new_node;
        this->tail = new_node;
        return;
    }

    void print(){
        if(head == nullptr) return;
        cout << "HEAD -> ";
        do{
            cout << this->head->data << " -> ";
            this->head = this->head->next;
        } while (this->head != this->tail->next);
        cout << "TAIL" << endl;
    }

};

int main(){

    CircularList Cl;
    Cl.push_back(10);
    Cl.push_back(20);
    Cl.push_back(30);
    Cl.push_back(40);
    Cl.push_back(50);

    Cl.print();

    return 0;
}
