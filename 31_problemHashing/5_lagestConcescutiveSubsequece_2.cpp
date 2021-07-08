/*==========================================
=            longest subsequece            =
==========================================*/
/**
 * ex. arr = [10,4,20,1,3,3,2,19,20]
 *
 * consecutive subsequence: 1,2,3,3,4   19,20  10 |  not-> 10,4 (as it is a sequence but not consecutive)
 *
 * only consider the unique nums: longest subsequence: (1,2,3,4) => 4
 */

/*===========================================
=            using unordered_map            =
===========================================*/
/**
 * streak = range of a consecutive numbers.
 *
 * Q. find the max_len streak in the array
 * => there can be 4 types of posible outcomes when we incounter a new arr element
 *
 * 1. new streak -> key(curr)--len(1)
 *
 * 2. left expansion of a prev streak -> key(curr)--len(prev_len + 1), key(right_most)--len(
 * prev_len + 1)
 * => we update the len of right_most element as left_most and right_most elements are only
 * one that have value to us.
 *
 * 3. right expansion of a prev streak -> key(curr)--len(prev_len + 1), key(left_most)--len(
 * prev_len + 1)
 * => we update the len of right_most element as left_most and right_most elements are only
 * one that have value to us.
 *
 * 4. curr element will connect 2 streaks -> key(curr)--len(prev_len_left + prev_len_right +
 * 1)
 * => update the left most element of the left_strak and right_most element of right_streak
 */

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int largestConsecSubsequence_hashmap(int arr[], int n){

    // number -- streak_len
    unordered_map<int, int> m;

    for(int i = 0; i < n; i++){

        int no = arr[i];

        // 1. new streak
        if(m.count(no-1)==0 and m.count(no+1)==0)
            m[i] = 1;

        // 2. left expansion
        else if(m.count(no+1) and m.count(no-1)){
            int len = m[no+1];
            m[no + len] = len + 1;
            m[no] = len + 1;
        }

        // 3. right expansion
        else if(m.count(no-1) and !m.count(no+1)){
            int len = m[no-1];
            m[no - len] = len + 1;
            m[no] = len + 1;
        }

        // 4. join of 2 streaks
        else{
            int left_len = m[no-1];
            int right_len = m[no+1];

            int streak = left_len + 1 + right_len;
            m[no-left_len] = streak;
            m[no+right_len] = streak;
        }
    }

    int largest = 0;
    for(auto p : m){
        largest = max(largest, p.second);
    }

    return largest;
}


int main(){

    int arr[] = {14,5,1,2,6,3,7,8,9,13,15,11,12,13,17,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << largestConsecSubsequence_hashmap(arr,n) << endl;

    return 0;
}
