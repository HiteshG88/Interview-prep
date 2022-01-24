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
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "target: ";
    int k;
    cin >> k;

    cout
        << floor(arr, n, k);

    return 0;
}