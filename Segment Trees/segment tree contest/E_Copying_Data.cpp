#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9; // Special value meaning "no update yet"
int seg[4 * 100005]; 
int a[100005]; // Array A
int b[100005]; // Array B

// Range Update: Assign 'val' (the shift x-y) to range [l, r]
void rangeUpdate(int ind, int low, int high, int l, int r, int val) {
    // Step 1: no overlap
    if (r < low || l > high)
        return;

    // Step 2: complete overlap
    if (low >= l && high <= r) {
        seg[ind] = val; // Assign the shift value
        return;
    }

    // Step 3: partial overlap - push the current seg value down first
    if (seg[ind] != INF) {
        seg[2 * ind + 1] = seg[ind];
        seg[2 * ind + 2] = seg[ind];
        
        // Reset current node to "no update"
        seg[ind] = INF;
    }

    int mid = (low + high) >> 1;
    rangeUpdate(2 * ind + 1, low, mid, l, r, val);
    rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
}

int query(int ind, int low, int high, int pos) {
    if (seg[ind] != INF) {
        return seg[ind];
    }

    if (low == high) {
        return seg[ind]; // Will return INF if nothing assigned
    }

    // No seg value here, search in children
    int mid = (low + high) >> 1;
    if (pos <= mid)
        return query(2 * ind + 1, low, mid, pos);
    else
        return query(2 * ind + 2, mid + 1, high, pos);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    fill(seg, seg + 4 * 100005, INF);

    while (m--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            rangeUpdate(0, 1, n, y, y + k - 1, x - y);
        } else {
            int x;
            cin >> x;
            int shift = query(0, 1, n, x);

            if (shift == INF) {
                cout << b[x] << "\n";
            } else {
                cout << a[x + shift] << "\n";
            }
        }
    }
    return 0;
}