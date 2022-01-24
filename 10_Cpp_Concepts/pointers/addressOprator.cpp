#include <iostream>
using namespace std;

int main() {

    int a = 10;
    cout << &a << endl;

    float b = 2.34;
    cout << &b << endl;

    char c = 'A';
    // does not work for char* as( << ) operator is overloaded for char*, but it will work if we type cast it to some other datatype like void* or int*
    cout << &c << endl;

    // explicit typecasting:
    cout << (void*)&c << endl;
    cout << (int*)&c << endl;

    return 0;
}
