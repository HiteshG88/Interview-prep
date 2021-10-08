#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int>* l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printGraph(){
        for(int i = 0; i < V; i++){
            cout << "vertex " << i << " -> ";
            for(auto nbr: l[i]){
                cout << nbr << ",";
            }
            cout << endl;
        }
    }
};

int main(){

    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);

    g.printGraph();

    return 0;
}
