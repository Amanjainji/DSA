#include <bits/stdc++.h>
using namespace std;

// Class to manage Disjoint Set Union
class DSU {
public:
    vector<int> parent, rank;

    // Initialize DSU with n nodes
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        // Initially, every node is its own parent
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find with path compression
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] < rank[py])
            parent[px] = py;
        else if(rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

// Solution class to calculate operations
class Solution {
public:
    // Function to find minimum operations to make the graph connected
    int makeConnected(int n, vector<vector<int>>& connections) {
        // If edges are less than n - 1, we can't connect
        if(connections.size() < n - 1) return -1;

        DSU dsu(n);

        // Connect components
        for(auto& edge : connections) {
            dsu.unite(edge[0], edge[1]);
        }

        // Count number of unique components
        unordered_set<int> components;
        for(int i = 0; i < n; i++) {
            components.insert(dsu.find(i));
        }

        // Return number of operations needed
        return components.size() - 1;
    }
};

// Driver code
int main() {
    int n = 5;
    vector<vector<int>> connections = {{2,3},{0,2},{0,3},{1,4}};
    Solution sol;
    cout << sol.makeConnected(n, connections) << endl;
    return 0;
}