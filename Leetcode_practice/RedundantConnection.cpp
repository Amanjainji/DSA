#include<bits/stdc++.h>
using namespace std;
void isCycleDFS_helper(int node, int parent, vector<bool> &visited, vector<vector<int>> &adj, bool &cycleDetected) {
    visited[node] = true;

    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            isCycleDFS_helper(neighbour, node, visited, adj, cycleDetected);
            if (cycleDetected) return;
        } else if (neighbour != parent) {
            // Cycle detected
            cycleDetected = true;
            return;
        }
    }
}

bool detectCycle(int n, vector<vector<int>> &adj) {
    vector<bool> visited(n + 1, false);
    bool cycleDetected = false;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            isCycleDFS_helper(i, -1, visited, adj, cycleDetected);
            if (cycleDetected) return true;
        }
    }

    return false;
}

vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<vector<int>> adj(n + 1); // Adjacency list for the graph

    for (auto &edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);

        // Check if adding this edge creates a cycle
        if (detectCycle(n, adj)) {
            return edge; // Return the redundant edge
        }
    }

    return {};
}

int main(){
    vector<vector<int>> edges1= {{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<vector<int>> edges={{1,2},{1,3},{2,3}};
    vector<int> k=findRedundantConnection(edges1);
    for(auto i: k){
        cout<<i<<" ";
    }
}