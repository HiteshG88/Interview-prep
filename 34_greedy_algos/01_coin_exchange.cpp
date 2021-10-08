#include <iostream>
using namespace std;

int floor_search(int arr[], int n, int t){
    int s = 0, e = n-1;
    while(s <= e){
        int m = s+(e-s)/2;
        if(arr[m] == t)
            return m;
        else if(arr[m] > t)
            e = m-1;
        else
            s = m+1;
    }
    return e;
}

void coinExchange(int coins[], int n, int money){
    while(money>0){
        int idx = floor_search(coins, n, money);
        cout << coins[idx] << " + ";
        money -= coins[idx];
    }
    return;
}

int main(){

    int coins[] = {1,2,5,10,20,50,100,200,500,1000,2000};
    int n = sizeof(coins)/sizeof(int);

    int money = 3700;

    coinExchange(coins, n, money);

    return 0;
}
