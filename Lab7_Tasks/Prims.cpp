#include <bits/stdc++.h>
using namespace std;
int main() {
    int V,E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<pair<int, int>>> adj(V + 1);
    cout << "Enter edges (u v weight):" << endl;
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> visited(V + 1, 0);
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;
    int mstCost = 0;
    pq.push({0, {1, -1}});
    cout << "Minimum Spanning Tree:" << endl;
    while(!pq.empty()) {
        int w = pq.top().first;
        int u = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();
        if(visited[u])
            continue;

        visited[u] = 1;
        if(parent != -1) {
            cout << parent << " - " << u << " : " << w << endl;
            mstCost += w;
        }
        for(auto edge : adj[u]) {
            int v = edge.first;
            int wt = edge.second;
            if(!visited[v])
                pq.push({wt, {v, u}});
        }
    }
    cout << "Minimum Cost = " << mstCost << endl;
    return 0;
}