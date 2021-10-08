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

    void dfs_helper(unordered_map<T, bool> &visited, int src, list<T> &ordering){

        cout << src << "->";
        visited[src] = true;

        for(auto nbr : l[src]){
            if(!visited[nbr]){
                dfs_helper(visited, nbr, ordering);
            }
        }
        ordering.push_front(src);
        return;
    }

    void dfs(T src){

        unordered_map<T, bool> visited;
        list<T> ordering;

        for(auto p : l){
            T node = p.first;
            visited[node] = false;
        }

        dfs_helper(visited, 0, ordering);

        cout << endl << "Topological Sort" << endl;
        for(auto val : ordering)
            cout << val << "<-";
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

    g.dfs(0);

    return 0;
}
