#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<T>> l;

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

        unordered_map<T, int> dist;
        queue<T> q;

        for(auto node_pair : l){
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;

        while(!q.empty()){

            T node = q.front();
            q.pop();

            for(auto nbr : l[node]){
                if(dist[nbr] == INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }

        for(auto node_pair : l){
            T node = node_pair.first;
            int d = dist[node];

            cout << "Distance is " << d << " for " << node << endl;
        }

    }
};

int main(){

    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.bfs(0);

    return 0;
}
