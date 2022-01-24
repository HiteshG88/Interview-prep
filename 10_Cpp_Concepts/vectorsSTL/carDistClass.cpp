#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Car {
public:
    string name;
    int x, y;

    Car(string n, int a, int b) {
        this->name = n;
        this->x = a;
        this->y = b;
    }

    int dist() {
        return x * x + y * y;
    }
};

bool compare(Car p1, Car p2) {
    int d1 = p1.dist();
    int d2 = p2.dist();

    if (d1 == d2)
        return p1.name.length() < p2.name.length();

    return d1 < d2;
}

int main() {
    int n; cin >> n;
    vector<Car> v;

    for (int i = 0; i < n; i++) {
        string name;
        int x, y; cin >> name >> x >> y;
        Car temp(name, x, y);
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    for (auto p : v) {
        cout << "Car: " << p.name << " : " << p.x << ", " << p.y << endl;
    }
}
