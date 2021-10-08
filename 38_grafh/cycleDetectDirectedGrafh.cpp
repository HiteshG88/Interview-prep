// Q. detect a cycle in a directed grafh
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
    }

    bool cycleHelper(bool* visited, bool* path, int src){

        visited[src] = true;
        path[src] = true;

        for(auto nbr : l[src]){
            if(path[nbr] == true)
                return true;

            else if(!visited[nbr]){
                bool found_cycle = cycleHelper(visited, path, nbr);
                if(found_cycle)
                    return true;
            }
        }

        path[src] = false;
        return false;
    }

    bool isCycle(int src){

        bool* visited = new bool[V];
        bool* path = new bool[V];

        for(int i = 0; i < V; i++)
            visited[i] = path[i] = false;

        return cycleHelper(visited, path, src);
    }

};


int main(){

    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(1, 5);
    g.addEdge(1, 2);
    g.addEdge(5, 6);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 2);

    cout << g.isCycle(0);

    return 0;
}
