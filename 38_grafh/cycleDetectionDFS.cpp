// Q. cycle detection using dfs
#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    list<int>* l;
    int V;

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int a, int b){
        l[a].push_back(b);
        l[b].push_back(a);
    }

    bool cycleHelper(bool* visited, int src, int parent){

        visited[src] = true;

        for(auto nbr : l[src]){

            if(!visited[nbr])
                return cycleHelper(visited, nbr, src);

            else if(nbr != parent)
                return true;
        }
        return false;
    }

    bool isCycle(int src){

        bool* visited = new bool[V];

        for(int i = 0; i < V; i++)
            visited[i] = false;

        return cycleHelper(visited, src, -1);
    }

};


int main(){

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // g.addEdge(4, 0);

    cout << g.isCycle(0);

    return 0;
}
