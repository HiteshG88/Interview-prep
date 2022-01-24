#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

string extractStringAtKey(string str, int key) {
    // strtok only accept char* type arr, and also return char* arr.
    char *s = strtok((char*)str.c_str(), " ");

    while (key > 1) {
        s = strtok(nullptr, " ");
        key--;
    }

    return (string)s;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
    string k1, k2;
    k1 = s1.second;
    k2 = s2.second;

    return stoi(k1) < stoi(k2);
}

bool lexicCompare(pair<string, string> s1, pair<string, string> s2) {
    string k1, k2;
    k1 = s1.second;
    k2 = s2.second;

    return k1 < k2;
}

int main() {
    int n; cin >> n;
    cin.get();  // for '\n'

    string arr[100];
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;

    // make a pair of original string and key string.
    pair<string, string> strPair[100];

    for (int i = 0; i < n; i++) {
        strPair[i].first = arr[i];
        strPair[i].second = extractStringAtKey(arr[i], key);
    }

    if (ordering == "numeric") {
        sort(strPair, strPair + n, numericCompare);
    } else {
        sort(strPair, strPair + n, lexicCompare);
    }

    if (reversal == "true") {
        for (int i = 0; i < n / 2; i++) {
            swap(strPair[i], strPair[n - i - 1]);
        }
    }

    // print the array
    for (int i = 0; i < n; i++) {
        cout << strPair[i].first << endl;
    }

    return 0;
}
