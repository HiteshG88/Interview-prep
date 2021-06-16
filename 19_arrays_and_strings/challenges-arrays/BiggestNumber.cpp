#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


/*

Suppose str1 and str2 are two strings and we want to compare these two strings then its syntax would look like:

int k= str1.compare(str2);
k==0 : If k contains value zero, it means both the strings are equal.
k!=0 : If k does contain value zero, it means both the strings are unequal.
k>0 : If k contains value more than zero, either the value of the first character is greater in the compared string or all the compared characters match but the compared string is longer.
k<0 : If k contains value less than zero, either the value of the first character is lower in the compared string or all the compared characters match but the compared string is shorter.

*/


bool compare(string a, string b){

    // ex: if a = 60 and b = 584
    // ab = 60584 and ba = 58460
    string ab = a.append(b);
    string ba = b.append(a);


    bool r = ab.compare(ba);

    if(r == 1)
        return a>b;  // put a before b
    else
        return a<b; // put b before a
}

int main(){

    int t; cin >> t;

    while(t--){

        int n; cin >> n;
        string arr[n];

        // take input:
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        // sort the string in decending order:
        sort(arr, arr+n, compare);

        for(auto i : arr)
            cout << i;

        cout << endl;

    }
    return 0;
}
