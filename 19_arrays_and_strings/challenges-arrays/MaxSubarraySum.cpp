#include <iostream>
using namespace std;
static int arr[100001] = {0};

int main() {
    int t; cin >> t;

    while (t--) {

        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int max_sum = 0, curr_sum = 0;
        for (int i = 0; i < n; i++) {
            curr_sum += arr[i];

            if (curr_sum < 0)
                curr_sum = 0;

            if (curr_sum > max_sum)
                max_sum = curr_sum;
        }

        cout << max_sum << endl;
    }

    return 0;
}
