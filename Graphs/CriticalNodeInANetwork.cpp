#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> d, low;
    int time = 0;

    void dfs(int u, vector<vector<int>>& connections,
             vector<vector<int>>& ad,
             vector<vector<int>>& b,
             int par) {

        d[u] = low[u] = ++time;

        for (int v : ad[u]) {
            if (d[v] == -1) {
                dfs(v, connections, ad, b, u);

                low[u] = min(low[u], low[v]);

                if (low[v] > d[u])
                    b.push_back({u, v});
            }
            else if (v != par) {
                low[u] = min(low[u], d[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ad(n);

        for (auto i : connections) {
            ad[i[0]].push_back(i[1]);
            ad[i[1]].push_back(i[0]);
        }

        d.resize(n, -1);
        low.resize(n);

        vector<vector<int>> b;

        for (int i = 0; i < n; i++) {
            if (d[i] == -1) {
                dfs(i, connections, ad, b, -1);
            }
        }

        return b;
    }
};

int main(){
    Solution s;
    vector<vector<int>> connections={{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> ans=s.criticalConnections(
        4, connections
    );
    for(auto i:ans){
        cout<<i[0]<<" "<<i[1]<<" "<<endl;
    }
}