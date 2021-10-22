#include <iostream>
using namespace std;

int fact(int arr[], int s, int curr_num){

    int carry = 0;

    for(int j = 0; j < s; j++){

        // old school way to do product.
        int product = arr[j]*curr_num + carry;

        // put the last dig of product into the jth position:
        arr[j] = product % 10;

        // except the last dig everything would be carry
        carry = product / 10;
    }

    // put carry on the next indexes:
    while(carry){

        // put last dig of carry.
        arr[s] = carry % 10;

        // update carry.
        carry = carry / 10;

        // increase size of the array
        s++;
    }

    return s;
}


int main(){

    // big num to be factorialed
    int n; cin >> n;

    // result array // note: array would be in reverse order.
    int arr[100000] = {0};
    arr[0] = 1;

    // size of array:
    int s = 1;

    for(int i = 2; i < n+1; i++){
        s = fact(arr,s,i);   // where i is the curr number.
    }

    // print array in reverse:
    for(int i = s-1; i > -1; i--)
        cout << arr[i];

    cout << endl;

    return 0;
}
