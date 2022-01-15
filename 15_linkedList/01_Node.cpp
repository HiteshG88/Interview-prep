// node class (datatype = integer)
// constructor node(int data)
struct node{
    int data;
    node* next;
    node(int d){
        data = d;
        next = nullptr;
    }
};