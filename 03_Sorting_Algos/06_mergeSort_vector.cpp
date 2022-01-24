#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> first, vector<int> second){

    vector<int> mix;
    mix.reserve(first.size() + second.size());

    int i = 0, j = 0;

    while(i < first.size() and j < second.size()){
        if(first[i] < second[j]){
            mix.push_back(first[i]);
            i++;
        }
        else{
            mix.push_back(second[j]);
            j++;
        }
    }

    while(i < first.size()){
        mix.push_back(first[i++]);
    }
    while(j < second.size()){
        mix.push_back(second[j++]);
    }

    return mix;
}

vector<int> mergeSort(vector<int> arr){
    if(arr.size() == 1)
        return arr;

    int mid = arr.size()/2;

    vector<int> first = {arr.begin(), arr.begin()+mid};
    vector<int> second = {arr.begin()+mid, arr.end()};

    first = mergeSort(first);
    second = mergeSort(second);

    return merge(first,second);
}

int main(int argc, char const *argv[])
{
    vector<int> v = {5,12,4,6,7,8,9,9,31,1,1,5,76,78,8};
    v = mergeSort(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
