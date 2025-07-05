#include <bits/stdc++.h>
using namespace std;

/*
🧠 Key Concepts:
disc[u]: Discovery time of node u

low[u]: Lowest discovery time reachable from u

inStack[u]: Whether node u is in the stack (used to detect back edges)

SCC: When low[u] == disc[u], that means we've found the root of an SCC.
*/
class TarjanSCC {   //TC - O(V+E)     SC - O(V+E)
    int V;
    vector<vector<int>> adj;
    vector<int> disc, low, inStack;
    stack<int> st;
    int timer;
    vector<vector<int>> ans;

    void dfs(int u) {
        disc[u] = low[u] = timer++;
        st.push(u);
        inStack[u] = 1;

        for (int v : adj[u]) {
            if (disc[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                // Back edge
                low[u] = min(low[u], disc[v]);
            }
        }

        // Found an SCC
        if (low[u] == disc[u]) {
            vector<int> scc;
            while (true) {
                int node = st.top();
                st.pop();
                inStack[node] = 0;
                scc.push_back(node);
                if (node == u) break;
            }
            sort(scc.begin(), scc.end()); // Optional: sort SCC
            ans.push_back(scc);
        }
    }

public:
    TarjanSCC(int V) {
        this->V = V;
        adj.resize(V);
        disc.assign(V, -1);
        low.assign(V, -1);
        inStack.assign(V, 0);
        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    vector<vector<int>> findSCCs() {
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1)
                dfs(i);
        }
        return ans;
    }
};

int main() {
    TarjanSCC g(8);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);
    g.addEdge(6, 5);
    g.addEdge(6, 7);

    vector<vector<int>> ans = g.findSCCs();

    cout << "Strongly Connected Components are:\n";
    for (auto &scc : ans) {
        for (int node : scc)
            cout << node << " ";
        cout << "\n";
    }

    return 0;
}
