#include <bits/stdc++.h>
using namespace std;

int ceiling(int arr[], int n, int k)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] == k)
            return m;
        else if (arr[m] < k)
            s = m + 1;
        else
            e = m - 1;
    }
    // just return start, as it will always points to next bigger number
    return arr[s];
}

int floor(int arr[], int n, int k)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] == k)
            return m;
        else if (arr[m] < k)
            s = m + 1;
        else
            e = m - 1;
    }
    // just return start, as it will always points to next bigger number
    return arr[e];
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 8;

    cout
        << ceiling(arr, n, k) << endl;

    return 0;
}