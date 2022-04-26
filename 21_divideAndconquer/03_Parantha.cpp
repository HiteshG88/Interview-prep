//https://hack.codingblocks.com/app/practice/1/102/problem

// The coding blocks members went to the success party of their first ever online boot-camp at Murthal. They ordered P number of paranthas. The stall has L cooks and each cook has a rank R. A cook with a rank R can cook 1 parantha in the first R minutes 1 more parantha in the next 2R minutes, 1 more parantha in 3R minutes and so on(he can only cook a complete parantha) ( For example if a cook is ranked 2.. he will cook one parantha in 2 minutes one more parantha in the next 4 mins and one more in the next 6 minutes hence in total 12 minutes he cooks 3 paranthas. In 13 minutes also he can cook only 3 paranthas as he does not have enough time for the 4th parantha). Calculate the minimum time needed to cook all the paranthas.

#include <iostream>
#include <algorithm>
using namespace std;

bool isPosible(int rank[], int n, int l, int curr_min) {

    int paranthas = 0;
    int time = 0;
    for (int i = 0; i < l; i++) {
        time = rank[i];
        int j = 2;
        while (time <= curr_min) {
            paranthas++;
            time += rank[i] * j;
            j++;
        }
        if (paranthas >= n)
            return true;
    }
    return false;
}

int main() {

    int n, l; cin >> n >> l;
    int rank[l];

    for (int i = 0; i < l; i++) {
        cin >> rank[i];
    }

    int s = 0;
    int e = n * (n + 1) / 2;
    int ans = 0; // time in mins

    while (s <= e) {
        int mid = (s + e) / 2;

        if (isPosible(rank, n, l, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}


// ======================================================================



//https://www.spoj.com/problems/PRATA/

//findout the minimum time to cook all the parathas


// #include<bits/stdc++.h>
// using namespace std;

// bool CanMakeParatha(long long int rank[], long long int cook, long long int paratha, long long int mid)
// {

//     // long long int count=0;
//     long long int ans1 = 0;
//     long long int res;
//     for (long long int i = 0; i < cook; i++)
//     {   res = 0;
//         res = sqrt((1 + (mid / rank[i]) * 8)) - 1;
//         res = res / 2;
//         // cout<<res<<endl;
//         ans1 += res;

//     }
//     if (ans1 >= paratha)
//     {
//         return true;
//     }



//     return false;


// }


// int main() {

//     long long int t = 1;
//     long long int paratha, cook;
//     long long int rank[100000];
//     while (t--)
//     {
//         cin >> paratha;
//         cin >> cook;


//         for (long long int i = 0; i < cook; i++)
//             cin >> rank[i];

//         long long int start = 0;
//         long long int end = paratha * (paratha + 1) / 2;
//         long long int ans = 0;

//         while (start <= end)
//         {
//             long long int mid = (start + end + 1) / 2;

//             bool parathaBanaPaye = CanMakeParatha(rank, cook, paratha, mid);

//             if (parathaBanaPaye)
//             {
//                 ans = mid;

//                 end = mid - 1;

//             }
//             else
//             {
//                 start = mid + 1;
//             }

//         }

//         if (cook == 0)
//         {
//             ans = 0;
//         }
//         cout << ans << endl;


//     }

//     return 0;

// }
