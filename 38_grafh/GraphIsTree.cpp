// Q. check if given graph is tree or not
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

    bool bfs(int src){

        bool* visited = new bool[V];
        int* parent = new int[V];
        queue<int> q;

        for(int i = 0; i < V; i++){
            visited[i] = false;
            parent[i] = i;
        }

        q.push(src);
        visited[src] = true;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto nbr : l[node]){

                if(visited[nbr] and parent[node] != nbr)
                    return false;

                else if(!visited[nbr]){
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return true;
    }
};


int main(){

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    cout << g.bfs(0);

    return 0;
}
