#include <iostream>
#include <stack>
using namespace std;

int histogram(int arr[], int n){

    int max_area = 0;
    stack<int> s;

    // push first elements index into stack
    s.push(0);

    // loop over rest of the array
    int i = 1;
    while(!s.empty() or i <= n){

        if(arr[i] > arr[s.top()])
            s.push(i);

        else{

            while(!s.empty() and arr[i] <= arr[s.top()]){

                int curr_min_hiegth = arr[s.top()];
                s.pop();

                int area = 0;

                if(s.empty()){
                    area = curr_min_hiegth*i;
                }
                else
                    area = curr_min_hiegth*(i - s.top() -1);

                if(area > max_area)
                    max_area = area;
            }
        }
        i++;
    }

    return max_area;
}

int main(){

    int arr[] = {6,2,5,4,5,1,6};
    int n = sizeof(arr)/sizeof(int);

    cout << histogram(arr, n) << endl;

    return 0;
}
