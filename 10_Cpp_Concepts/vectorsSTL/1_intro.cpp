#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;

    return;
}

void display_It(vector<int> v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;

    return;
}

void display_forEach(vector<int> v) {
    for (auto i : v) {
        cout << i << ", ";
    }
    cout << endl;

    return;
}

int main() {

    vector<int> v1;
    vector<int> v2(5, 10); // init vector with 10 value for 5 palces.
    vector<int> v3(v2.begin(), v2.end()); // copy all the elements from v2 begin to end.
    vector<int> v4{1, 2, 3, 4, 5, 6};

    cout << v4.size() << endl; // size of the vector
    cout << v4.capacity() << endl; //underlying size of the array
    cout << v4.max_size() << endl; // max size of the array in worst case

    display_forEach(v4);
    return 0;
}
