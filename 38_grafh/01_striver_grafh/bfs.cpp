#include <bits/stdc++.h>
using namespace std;

// 2. print a grafh using bfs
vector<int>bfsOfGraph(int V, vector<int> adj[]){
    vector<int> bfs; 
    vector<int> vis(V+1, 0); 
    queue<int> q; 
    q.push(0); 
    vis[0] = 1;  
    while(!q.empty()) {
        int node = q.front();
        q.pop(); 
        bfs.push_back(node); 
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                q.push(it); 
                vis[it] = 1; 
            }
        }
    }
    
    return bfs; 
}

int main()
{
// make a grafh, k is the number of nodes present in the grafh

    return 0;
}