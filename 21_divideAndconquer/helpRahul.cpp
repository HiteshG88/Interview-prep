// https://hack.codingblocks.com/app/practice/1/1044/problem
/*
Rahul had a sorted array of numbers from which he had to find a given number quickly. His friend by mistake rotated the array. Now Rahul doesn't have time to sort the elements again. Help him to quickly find the given number from the rotated array.

Hint - Think Binary Search!
*/

#include <iostream>
using namespace std;

int find_num(int arr[], int n, int k) {

    int s = 0, e = n - 1;
    while (s <= e) {
        int mid = (s + e) / 2;

        if (arr[mid] == k)
            return mid;

        else if (arr[s] <= arr[mid]) {

            if (k >= arr[s] and k <= arr[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        else {

            if (k >= arr[mid] and k <= arr[e])
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n; cin >> n;
    int arr[n];

    for (int  i = 0; i < n; i++)
        cin >> arr[i];

    int key; cin >> key;

    cout << find_num(arr, n, key) << endl;
}
