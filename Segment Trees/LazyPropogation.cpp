#include <bits/stdc++.h>
using namespace std;

int seg[4 * 100005];
int lazy[4 * 100005];
int a[100005];

//Lazy propagation delays range updates by storing them in a lazy array and applies them only when the segment is accessed.

// Build segment tree
void build(int ind, int low, int high) {
    if (low == high) {
        seg[ind] = a[low];
        return;
    }

    int mid = (low + high) >> 1;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

// Range update: add val to range [l, r]
void rangeUpdate(int ind, int low, int high, int l, int r, int val) {

    // Step 1: resolve pending lazy update
    if (lazy[ind] != 0) {
        seg[ind] += (high - low + 1) * lazy[ind];

        if (low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    // Step 2: no overlap
    if (r < low || l > high)
        return;

    // Step 3: complete overlap
    if (low >= l && high <= r) {
        seg[ind] += (high - low + 1) * val;

        if (low != high) {
            lazy[2 * ind + 1] += val;
            lazy[2 * ind + 2] += val;
        }
        return;
    }

    // Step 4: partial overlap
    int mid = (low + high) >> 1;
    rangeUpdate(2 * ind + 1, low, mid, l, r, val);
    rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

// Range sum query
int querySumLazy(int ind, int low, int high, int l, int r) {

    // Step 1: resolve pending lazy update
    if (lazy[ind] != 0) {
        seg[ind] += (high - low + 1) * lazy[ind];

        if (low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    // Step 2: no overlap
    if (r < low || l > high)
        return 0;

    // Step 3: complete overlap
    if (low >= l && high <= r)
        return seg[ind];

    // Step 4: partial overlap
    int mid = (low + high) >> 1;
    return querySumLazy(2 * ind + 1, low, mid, l, r) +
           querySumLazy(2 * ind + 2, mid + 1, high, l, r);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(0, 0, n - 1);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            rangeUpdate(0, 0, n - 1, l, r, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << querySumLazy(0, 0, n - 1, l, r) << endl;
        }
    }
}
