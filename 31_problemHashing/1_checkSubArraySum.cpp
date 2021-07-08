#include <iostream>
#include <unordered_map>
using namespace std;

bool checkSum(int arr[], int n){

    // make a cummulative sum array
    for(int i = 1; i < n; i++)
        arr[i] = arr[i-1]+arr[i];

    // cumm sum arr
    // for(int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;

    // if a num in cumm arr will be repeated means, there exist a 0 sum subArr in arr.
    unordered_map<int, bool> um;
    for(int i = 0; i < n; i++){
        if(um[arr[i]] == true)
            return true;
        else
            um[arr[i]] = true;
    }
    return false;
}


int main(){

    int arr[] = {6,-1,6,1,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    if(checkSum(arr,n))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
