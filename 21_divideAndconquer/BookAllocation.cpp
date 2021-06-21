// https://hack.codingblocks.com/app/practice/1/1365/problem
/*
You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool bookAllocationHandler(int book[], int n, int m, int curr_min) {
    int studentUsed = 1;
    int pages_read = 0;

    // add the pages to the curr_student till it is more than curr_min.
    for (int i = 0; i < n; i++) {
        if (pages_read + book[i] > curr_min) {
            studentUsed++;
            pages_read = book[i];
            if (studentUsed > m)
                return false;
        }
        else {
            pages_read += book[i];
        }
    }
    return true;
}

int main() {

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int book[1000];

        int sumAllPages = 0;
        for (int i = 0; i < n; i++) {
            cin >> book[i];
            sumAllPages += book[i];
        }

        // defining the monotonic search space:
        // 1. start = atleat one book per student. so, n-1 because last book would contain most pages.
        // 2. end = if all the books was read by one student, (sum of all pages).
        int s = book[n - 1];
        int e = sumAllPages;
        int ans = 0;

        while (s <= e) {
            int mid = (s + e) / 2;

            bool bookAllocation = bookAllocationHandler(book, n, m, mid);

            // because if curr_min(mid) is true than so all the book more than curr_mid. so we reduce the search space from end.
            if (bookAllocation) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
