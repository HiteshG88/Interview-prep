#include <iostream>
using namespace std;

int main(){

    int n; cin >> n;
    int arr[100005];

    int res = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        res = res ^ arr[i];
    }

    int temp = res;
    int pos = 0;
    while((temp&1) == 0){
        pos++;
        temp>>1;
    }

    int mask = (1 << pos);

    int a = 0;
    for(int i = 0; i < n; i++){
        if((mask&arr[i])!=0)
            a = a ^ arr[i];
    }

    int b = a^res;

    cout << min(a,b) << " " << max(a,b) << endl;

    return 0;
}
