#include <iostream>
#include <unordered_map>
using namespace std;

int longestSumArrWith0Sum(int arr[], int n){

   unordered_map<int, int> m;
   int len = 0;
   int pre = 0;

   for(int i = 0; i < n; i++){
        // compute the preSumArr
        pre += arr[i];

        // case 1. arr[i] is zero then len = i+1
        if(pre == 0){
            len = max(len, i+1);
        }

        // case 2. element is already present in the map:
        if(m.find(pre) != m.end()){
            len = max(len, i - m[pre]);
        }
        // case 3. update the map if it is the first occ.
        else{
            m[pre] = i;
        }
   }
   return len;
}


int main(){

    int arr[] = {0, -1, 1, 2, 5, -5, -2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << longestSumArrWith0Sum(arr,n) << endl;

    return 0;
}
