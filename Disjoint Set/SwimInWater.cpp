#include <bits/stdc++.h>
using namespace std;
/*
//Heap - BFS
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>visit(n, vector<int>(n,0));

        pq.push({grid[0][0],{0,0}});
        int ans = 0;
        vector<int>dirx{1,-1,0,0};
        vector<int>diry{0,0,1,-1};

        while(!pq.empty()){
            auto it = pq.top();
            int elevate = it.first;
            int xcor = it.second.first;
            int ycor = it.second.second;

            if(xcor==n-1 && ycor == n-1) return elevate;
            pq.pop();

            for(int i=0; i<4; i++){
                int newx = xcor + dirx[i];
                int newy = ycor + diry[i];

                if(newx<0 || newx>=n || newy<0 || newy>=n || visit[newx][newy])continue;
                visit[newx][newy] = 1;
                pq.push({max(elevate, grid[newx][newy]), {newx, newy}});
            }
        }
        return ans;
    }
};*/

//Disjoint Set
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> edges;  // {cost, u, v}

        // Create edges between adjacent cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0)
                    edges.push_back({max(grid[i][j], grid[i - 1][j]), i * n + j, (i - 1) * n + j});
                if (j > 0)
                    edges.push_back({max(grid[i][j], grid[i][j - 1]), i * n + j, i * n + j - 1});
                }
            }


        // Sort edges by cost
        sort(edges.begin(), edges.end());

        // Initialize DSU
        DisjointSet ds(m * n);

        // Process edges in ascending order of cost
        for (auto&i : edges) {
            int cost=i[0];
            int u=i[1];
            int v=i[2];
            ds.unionBySize(u, v);
            if (ds.findUPar(0) == ds.findUPar(m * n - 1))
                return cost;
        }

        return grid[0][0];  // fallback (should never reach here)
    }
};

int main(){
    return 0;
}