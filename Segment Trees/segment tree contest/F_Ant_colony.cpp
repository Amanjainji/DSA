#include <bits/stdc++.h>
using namespace std;

// We need a structure to hold the GCD and how many times it appears
struct Node {
    int g;      // The GCD of the range
    int count;  // Frequency of this GCD in the range
};

int a[100005];
Node seg[4 * 100005]; // Modified to store Nodes instead of ints

// Helper function to calculate GCD
int get_gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Helper function to merge two nodes
Node merge(Node left, Node right) {
    // If one node is empty (from out of bounds query), return the other
    if (left.g == -1) return right;
    if (right.g == -1) return left;

    Node res;
    res.g = get_gcd(left.g, right.g);
    res.count = 0;

    // If left child's GCD contributes to the new GCD, add its count
    if (left.g == res.g) res.count += left.count;
    
    // If right child's GCD contributes to the new GCD, add its count
    if (right.g == res.g) res.count += right.count;

    return res;
}

// Build the segment tree
void build(int ind, int low, int high) {
    if (low == high) {
        // Leaf node: GCD is the number itself, count is 1
        seg[ind] = {a[low], 1};
        return;
    }

    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);

    // Merge logic replaces max()
    seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
}

// Range query
Node query(int ind, int low, int high, int l, int r) {
    // complete overlap
    if (low >= l && high <= r) {
        return seg[ind];
    }

    // no overlap -> return a "null" node
    if (high < l || low > r) {
        return {-1, 0}; 
    }

    // partial overlap
    int mid = (low + high) / 2;
    Node left = query(2 * ind + 1, low, mid, l, r);
    Node right = query(2 * ind + 2, mid + 1, high, l, r);

    return merge(left, right);
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(0, 0, n - 1);

    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        
        // Convert 1-based index to 0-based
        l--; r--; 

        Node res = query(0, 0, n - 1, l, r);
        
        // Logic for Ant Colony:
        // Ants eaten = (Total ants in range) - (Ants with strength == Range GCD)
        int total_ants = r - l + 1;
        cout << total_ants - res.count << "\n";
    }

    return 0;
}