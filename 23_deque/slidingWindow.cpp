#include <iostream>
#include <cstring>
using namespace std;

int main(){

    char a[] = "abcc";
    int n = sizeof(a)/sizeof(a[0]);

    int curr_len = 1;
    int max_len = 1;

    int visited[256];

    // frequency map of ascii values of abcd....
    for(int i = 0; i < 257; i++)
        visited[i] = -1;

    // as the index of a is 0 int the a[]
    visited[a[0]] = 0;

    for(int i = 1; i < n; i++){

        // index of the a[i] in visited array
        int last_ocr = visited[a[i]];

        // (i - curr_len) denotes the start of the window
        if(last_ocr == -1 || i - curr_len > last_ocr){
            curr_len += 1;
        }
        else{
            // update the max_len as we will be reducing our curr_len
            max_len = max(curr_len, max_len);

            // reduce the curr_len (by changing the starting pos of window) as either same num is present in our widow
            curr_len = i - curr_len;
        }
        max_len = max(curr_len, max_len);

        // update the visited array
        visited[a[i]] = i;
    }

    cout << max_len << endl;

    return 0;
}
