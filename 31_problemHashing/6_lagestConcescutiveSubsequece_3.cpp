/*============================================================================
=            longest consecutive subsequence using unoredered_set            =
============================================================================*/
/*
1. put all the elements in set.
2. traverse the arr
-> if a[i]-1 element present in the set, skip that element.
-> if a[i]-1 element not present in set (then it can be a start of a new strek).
    => count all the next element (curr+1) till no next element can be found.
    => update the max_len.
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int largestConsecSubsequence_set(int a[], int n){

    unordered_set<int> s;

    // 1. put all the elements in set.
    for(int i = 0; i < n; i++)
        s.insert(a[i]);

    int max_len = 1;
    // 2. traverse the arr
    for(int i = 0; i < n; i++){

        // if a[i]-1 element not present in set (then it can be a start of a new strek).
        if(s.find(a[i]-1)==s.end()){
            int streak_len = 1;
            int next_no = a[i]+1;

            // => count all the next element (curr+1) till no next element can be found.
            while(s.find(next_no) != s.end()){
                next_no += 1;
                streak_len += 1;
            }
            // update the max_len.
            max_len = max(max_len, streak_len);
        }
    }
    return max_len;
}

int main(){

    int arr[] = {14,5,1,2,6,3,7,8,9,13,15,11,12,13,17,10}; // 10
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << largestConsecSubsequence_set(arr,n) << endl;

    return 0;
}


