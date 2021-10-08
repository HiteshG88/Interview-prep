// Q. find the shortest path in the weighted grafh.
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
private:
    unordered_map< T, list< pair<T,int> > > m;

public:
    void addEdge(T a, T b, int w, bool bidir = true){
        m[a].push_back(make_pair(b,w));
        if(bidir)
            m[b].push_back(make_pair(a,w));
    }

    void printAdj(){
        for(auto p : m){
            cout << p.first << " -> ";
            for(auto q : p.second){
                cout << "(" << q.first << "," << q.second << ") - ";
            }
            cout << endl;
        }
    }

    void dijkstraSPWG(T src){

        map<T, int> dist;
        for(auto p : m){
            dist[p.first] = INT_MAX;
        }

        // first parameter is distance as set do internal ordering acc. to its first para.
        set< pair<int, T> > s;

        dist[src] = 0;
        s.insert(make_pair(0, src));

        while(!s.empty()){

            // find the pair at the front.
            auto f = *(s.begin());
            T node = f.second;

            int nodeDist = f.first;

            // erase the node from the set.
            s.erase(s.begin());

            // itearte over nbr of current node.
            for(auto childPair : m[node]){

                if(nodeDist + childPair.second < dist[childPair.first]){

                    // in set updation is not possible
                    // so we have to delete the first pair and insert the new one.
                    T dest = childPair.first;
                    auto p = s.find( make_pair(dist[dest], dest) );

                    if(p != s.end()){
                        s.erase(p);
                    }

                    // insert a new pair.
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }

        }
        for(auto val : dist){
            cout << val.first << " = " << val.second << endl;
        }

    }

};

int main(){

    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);

    // g.printAdj();
    g.dijkstraSPWG(1);

    return 0;
}
