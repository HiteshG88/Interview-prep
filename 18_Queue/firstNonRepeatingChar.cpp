#include <iostream>
#include <queue>
using namespace std;


int main(){

    queue<char> q;
    int freq[27] = {0}; // initial freq of all chars are 0

    char ch; cin >> ch;  // running stream of characters.

    while(ch != '.'){

        // 1. push the element in queue and update the freq array.
        q.push(ch);
        freq[ch - 'a']++;

        while(!q.empty()){

            // we have to print the first char in queue if its freq is 1.
            int idx = q.front() - 'a';

            if(freq[idx] > 1){
                q.pop();
            }
            else{
                cout << q.front() << " ";
                break;
            }
        }

        if(q.empty())
            cout << "-1 ";

        cin >> ch;
    }

    return 0;
}
