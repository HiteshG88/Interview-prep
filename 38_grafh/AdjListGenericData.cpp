#include <iostream>
#include <list>
#include <cstring>
#include <unordered_map>
using namespace std;

class Grafh{

    unordered_map<string, list<pair<string, int>> > l;

public:
    void addEdge(string x, string y, bool bdir, int w){

        l[x].push_back(make_pair(y, w));
        if(bdir){
            l[y].push_back(make_pair(x,w));
        }
    }

    void printGrafh(){

        for(auto p : l){
            string city = p.first;
            list<pair<string, int>> nbrs = p.second;

            cout << "City " << city << " : ";
            for(auto nbr: nbrs){
                string nbr_city = nbr.first;
                int w = nbr.second;

                cout << "(" << nbr_city << ", " << w << ") -> ";
            }
            cout << endl;
        }
    }
};

int main(){

    Grafh g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);

    g.printGrafh();
}
