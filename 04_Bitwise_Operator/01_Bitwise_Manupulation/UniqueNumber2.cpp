#include <iostream>
using namespace std;

int findUnique(int arr[], int n) {
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = ans ^ arr[i];

    return ans;
}

int main() {

    int n; cin >> n;
    int res = 0;
    int arr[10005];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // 1. find the xor of all numbers.
    // res will contain the xor of 2 unique numbers present in array.
    res = findUnique(arr, n);

    // 2. find the pos of first setBit.
    int temp = res;
    int pos = 0;

    while((temp&1) == 0){
        pos++;
        temp = temp>>1;
    }

    //3. create a mask with 1 at positon pos.
    int mask = 1<<pos;

    //4. aganin do xor of mask with all the nums in array, as it will only return true with one of the nums in res, and all other nums who have bit at same pos will get cancel out because of xor.
    int num1 = findUnique(arr, mask);

    int num2 = num1^res;

    cout << min(num1,num2) << " " << max(num1,num2);

    return 0;
}
