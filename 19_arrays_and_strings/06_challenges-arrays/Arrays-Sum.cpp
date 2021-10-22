#include <iostream>
#include <vector>
using namespace std;

static vector<int> ans;

void inputArr(int arr[], int n){
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    return;
}

void arraySum(int a[], int b[], int n, int m){

    // 1. find the bigger array.
    int big, small;
    int* bigArr, *smallArr;

    if(n > m){
        bigArr = a;
        smallArr = b;
        big = n;
        small = m;
    }else{
        bigArr = b;
        smallArr = a;
        big = m;
        small = n;
    }

    int carry = 0;
    int i = big-1;
    int j = small-1;

    // 2. iterate to add all the nums of smaller array.
    while(j >= 0){

        // cout << carry << endl;
        int num = bigArr[i] + smallArr[j] + carry;
        carry = num/10;
        num = num%10;
        ans.push_back(num);

        i--;j--;
    }

    // 3. iterate over the left bigger array
    while(i >= 0){

        int num = bigArr[i] + carry;
        carry = num/10;
        num = num%10;
        ans.push_back(num);
        i--;

    }

    // add if any carry left.
    while(carry){
        ans.push_back(carry);
        carry = carry/10;
    }

    return;
}


int main(){

    int n; cin >> n;
    int arr1[1001], arr2[1001];

    inputArr(arr1, n);

    int m; cin >> m;
    inputArr(arr2, m);

    arraySum(arr1, arr2, n , m);

    for(int i = ans.size()-1; i >= 0; i--)
        cout << ans[i] << ", ";

    cout << "END";

    return 0;
}
