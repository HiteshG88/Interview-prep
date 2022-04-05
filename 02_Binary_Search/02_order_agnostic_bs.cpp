#include <iostream>
using namespace std;

// @info: type of Binary Search were we dont know if the arr is assending or desc
int orderAgnosticBS(int arr[], int n, int k)
{
    int s = 0, e = n - 1;

    bool isAsc = arr[s] < arr[e];

    while (s <= e)
    {
        int m = s + (e - s) / 2;

        if (arr[m] == k)
            return m;

        if (isAsc)
        {
            if (arr[m] < k)
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
        else
        {
            if (arr[m] < k)
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
    }
    return -1;
}

int binarySearch(int arr[], int s, int e, int k)
{
    if (s > e)
        return -1;
    int mid = s + (e - s) / 2;
    if (arr[mid] == k)
        return mid;
    if (arr[mid] > k)
    {
        return binarySearch(arr, s, mid - 1, k);
    }
    return binarySearch(arr, mid + 1, e, k);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "target: ";
    int k;
    cin >> k;

    cout << endl
         << binarySearch(arr, 0, n - 1, k);

    return 0;
}
