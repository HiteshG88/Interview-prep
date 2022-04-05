#include <iostream>
#include <algorithm>
using namespace std;

void kadaneAlgo_for_maxSum(int arr[], int n) {
    int max_sum = 0, curr_sum = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];
        if (curr_sum < 0) {
            curr_sum = 0;
        }

        max_sum = max(max_sum, curr_sum);
    }
    cout << "Max sum is: " << max_sum;
}


void maxSubArray(int arr[], int cs_arr[], int n) {
    int max_sum = 0, curr_sum = 0;  // max sum encountered so far
    int left = -1;  // starting of max subArray
    int right = -1; // ending of max subArray

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            // imp step: as cs_arr[j] is the sum of arr till j index, if we suntract cs_arr[i-1] index then we get the sum of arr between i-1 and j.
            curr_sum = cs_arr[j] - cs_arr[i - 1];

            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                left = i;
                right = j;
            }
        }
    }

    cout << max_sum << endl;
    for (int i = left; i <= right; i++)
        cout << arr[i] << ", ";

    return;
}


void fillArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return;
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }
    return;
}

int main() {
    int n; cin >> n;
    int arr[n];

    // make an arr cummulative sum array:
    // which store the sum of all element till that curr(including) element.
    int cs_arr[n];

    cin >> arr[0];
    cs_arr[0] = arr[0];

    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        cs_arr[i] = cs_arr[i - 1] + arr[i];
    }

    // maxSubArray(arr, cs_arr, n);

    kadaneAlgo_for_maxSum(arr, n);

    return 0;
}
