#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<T>> l

public:
    void addEdge(T a, T b){
        l[a].push_back(b);
        l[b].push_back(a);
    }

    void printGrafh(){
        for(auto p : l){
            cout << p.first << " : ";
            for(auto nbr : p.second){
                cout << nbr.first << "->";
            }
            cout << endl;
        }
    }

    void bfs(T src){

        unordered_map<T, bool> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){

            T node = q.front();
            q.pop();

            for(auto nbr : l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};

int main(){



    return 0;
}
