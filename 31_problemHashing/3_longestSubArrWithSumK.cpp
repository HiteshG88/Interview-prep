#include <iostream>
#include <unordered_map>
using namespace std;

int longestSumArrWithKSum(int arr[], int n, int k){

   unordered_map<int, int> m;
   int len = 0;
   int pre = 0;

   for(int i = 0; i < n; i++){
        // compute the preSumArr
        pre += arr[i];

        // case 1. pre is k then len = i+1
        if(pre == k){
            len = max(len, i+1);
        }
        // case 2. element is already present in the map: (cumSum_j - cummSum_i = k)
        if(m.find(pre - k) != m.end()){
            len = max(len, i - m[pre-k]);
        }
        // case 3. update the map if it is the first occ.
        else{
            m[pre] = i;
        }
   }
   return len;
}


int main(){

    int arr[] = {1, -1, 5, -2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout << longestSumArrWithKSum(arr,n,k) << endl;

    return 0;
}
