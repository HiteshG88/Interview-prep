/*====================================================================
=              find the pattern in string using sliding Window         =
====================================================================*/
/*

string -> "helllaoeeo world"
pattern -> "ello"

1. handle corner cases, if pat.length() > str.length()
2. make a pat freq arr to store the characters freq
3. Expand toward right to get the window, once you get the window contarct toward the left to avoid un-required character (either the char is not present or the freq is higher than expected)
4. every time you get a window update the min window
5. return the min pattern.

*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

string find_min_window(string s, string p){

    int SL = s.length();
    int PL = p.length();

    // 1. handle corner cases, if pat.length() > str.length()
    if(PL > SL)
        return "none";

    int FS[256] = {0};
    int FP[256] = {0};

    // 2. make a pat freq arr to store the characters freq
    for(int i = 0; i < PL; i++){
        char ch = p[i];
        FP[ch]++;
    }

    int min_len = INT_MAX;
    int count = 0;
    int start = 0;
    int start_idx = -1;

    for(int i = 0; i < SL; i++){
        char ch = s[i];
        FS[ch]++;

        // keep track of the characters matched
        if(FP[ch] != 0 and FS[ch] <= FP[ch]){
            count++;
        }

        // if all the characters match
        if(count == PL){
            // start shrinking the window
            // remove all unwanted characters
            char temp = s[start];
            while(FP[temp] == 0 or FS[temp] > FP[temp]){
                FS[temp]--;
                start++;
                temp = s[start];
            }

            // update the min window after contract
            int window_len = i - start + 1;

            if(window_len < min_len){
                min_len = window_len;
                start_idx = start;
            }
        }
    }
    if(start_idx == -1)
        return "none";

    // cout << min_len << endl;

    string ans = s.substr(start_idx, min_len);
    return ans;
}

int main(){

    string s = "hlelloeaeo world";
    string p = "ello";

    cout << find_min_window(s,p) << endl;

    return 0;
}

