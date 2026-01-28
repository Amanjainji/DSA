#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 300005;
int parent[MAXN];
int ans[MAXN];

// Find parent function with path compression
int find_parent(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_parent(parent[v]);
}

int main() {
    int n, m;
    if (cin >> n >> m) {
        for (int i = 1; i <= n + 1; ++i) {
            parent[i] = i;
        }

        for (int i = 0; i < m; ++i) {
            int l, r, x;
            cin >> l >> r >> x;

            // Start iterating from the first alive knight in the range [l, r]
            int cur = find_parent(l);

            while (cur <= r) {
                if (cur == x) {
                    cur = find_parent(cur + 1);
                } else {
                    // Knight 'cur' is beaten by 'x'
                    ans[cur] = x;

                    // Remove 'cur' from the set of active knights.
                    // We do this by setting 'cur's parent to the next alive knight (cur + 1).
                    // This effectively "skips" cur in future find operations.
                    parent[cur] = find_parent(cur + 1);
                    
                    // Move to the next alive knight (which is now the parent of cur)
                    cur = parent[cur]; 
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}