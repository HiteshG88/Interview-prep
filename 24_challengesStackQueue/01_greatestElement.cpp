#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

// brute Force:
void FindNextGreatest(int a[], int n){

    // trverse the array from i+1
    // till we dont find the next greater num or same num
    // as array is circular

    for(int i = 0; i < n; i++){

        int j = i+1;
        int curr = a[i];

        while(j != i and a[j] < curr + 1){
            if(j > n)
                j = j % n;
            j++;
        }

        // no element is found
        if(j == i)
            cout << -1 << " ";
        else
            cout << a[j] << " ";
    }

    return;
}

// optimized aproach (using stack and unordered_map):
/*
1. copy the array again behind the first arr, make a stack s, and a unordered_map m
2. push first element of arr in stack s, set curr = i+1.
3. traverse the circular arr:
    -> if map conatin the a[i] then continue
    -> while !s.empty and curr > s.top, m[s.top] = curr, and pop the top elemnts
    -> s.push(curr)
    -> increment curr
4. put -1 for remaining elements in stack
5. print the map according to arr ordering cout << arr[i] << " " << m[arr[i]];
*/

void FindNextGreatest_opt(int a[], int n){

    stack<int> s;
    unordered_map<int, int> m; // arr[i] -> nextGreaterElement

    // push first element in stack
    s.push(a[0]);

    for(int i = 1; i < n*2; i++){

        if(m.count(a[i]))
            continue;

        while(!s.empty() and a[i] > s.top()){
            m[s.top()] = a[i];
            s.pop();
        }

        s.push(a[i]);
    }

    while (!s.empty())
    {
        m[s.top()] = -1;
        s.pop();
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " -> " << m[a[i]] << endl;
    }
    return;
}


int main(){

    int n; cin >> n;
    int* arr = new int[n*2];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = n;i < 2*n; i++)
        arr[i] = arr[i-n];

    FindNextGreatest_opt(arr,n);

    return 0;
}


// 5 2 1 5 3 4
