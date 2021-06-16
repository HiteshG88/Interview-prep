#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> v) {
    for (auto i : v) {
        cout << i << ", ";
    }
    cout << endl;
    return;
}

int main() {

    vector<int> v1{1, 2, 3, 4, 5};

    // for appending the no. after the vector.
    v1.push_back(16);

    // insert elements in middle
    // insert(starting address, optional: frequency, value)
    // time: O(n)
    v1.insert(v1.begin() + 2, 10, 100);

    // erase(starting address, ending address)
    v1.erase(v1.begin() + 2, v1.end() - 9);

    // erase/clear/delete the elements from vector, does not delete the memory occupy by the array,
    // v1.clear();
    // cout << v1.capacity() << endl;

    cout << v1.front() << endl;
    cout << v1.back() << endl;


    display(v1);
    return 0;
}
