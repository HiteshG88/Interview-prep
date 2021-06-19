// shallow copy is done by the inbuild copy constructor of the class
// deep copy is reqired when we have some dynamically allocated memory in our class.

#include <iostream>
#include <cstring>
using namespace std;

class Car{
    float price;

public:
    char *name;
    int model_no;

    Car(){
        name = nullptr;
    }

    Car(float p, char *n, int m){
        price = p;
        model_no = m;
        name = new char[strlen(n)];
        strcpy(name, n);
    }

    Car(Car &X){
        price = X.price;
        model_no = X.model_no;

        // deep copy.
        // dynamically allocate it to new memory
        name = new char[strlen(X.name)+1];
        strcpy(name, X.name);
    }

    void print(){
        cout << "name: " << name << endl;
        cout << "model no: " << model_no << endl;
        cout << "price: " << price << endl;
    }

    ~Car(){
        cout << "destroying Car: " << name << endl;
        if(name != nullptr){
            delete [] name;
        }
    }
};

int main(){

    char s[] = "BMW";
    Car c(100.0, s, 1);

    Car d = c;

    d.name[0] = 'A';

    c.print();
    d.print();
}
