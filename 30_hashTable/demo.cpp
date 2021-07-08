#include <iostream>
#include <string>
#include "hashTable.hpp"
using namespace std;

int main(){
    hashTable<int> h;

    h.insert("burger", 120);
    h.insert("samosa", 12);
    h.insert("sandwitch", 30);
    h.insert("pepsi", 40);
    h.insert("coke", 30);

    h.print();

    int* price = h.search("cokee");

    h["dosa"] = 60;
    h["dosa"] += 10;

    cout << h["dosa"] << endl;

    // if(price == nullptr)
    //     cout << "key not present" << endl;
    // else
    //     cout << *price << endl;
}
