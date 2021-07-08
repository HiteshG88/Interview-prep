/*==========================================
=            longest subsequece            =
==========================================*/
/**
 *
 * ex. arr = [10,4,20,1,3,3,2,19,20]
 *
 * consecutive subsequence: 1,2,3,3,4   19,20  10 |  not-> 10,4 (as it is a sequence but not consecutive)
 *
 * only consider the unique nums: longest subsequence: (1,2,3,4) => 4
 */

/*=====  End of longest subsequece  ======*/

#include <iostream>
#include <algorithm>
using namespace std;

// method 1. sort the array and then count the unique subsequence.
int bruteForce(int arr[], int n){

    // 1. sort the array
    sort(arr, arr+n);

    int count = 0;
    int max_len = 0;

    // 2. iterate arr, and count unique consecutive nums
    for(int i = 1; i < n; i++){
        if(arr[i-1] == arr[i] or arr[i-1] == arr[i]-1)
            count++;
        else{
            max_len = max(max_len, count);
            count = 0;
        }
    }
    return max_len;
}


int main(){

    int arr[] = {10,4,20,1,3,3,2,19,20};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << bruteForce(arr,n) << endl;

    return 0;
}
