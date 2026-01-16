#include <bits/stdc++.h>
using namespace std;

/*
 Fenwick Tree / Binary Indexed Tree
 - 1-indexed
 - Supports:
   1) Point update
   2) Prefix sum query
   3) Find smallest index with prefix sum >= k
*/

const int N = 100000;   // Maximum size
int n;                 // Actual size of array
int ft[N + 1];         // Fenwick Tree array

// Add `val` to index `i`
void update(int i, int val) {
    while (i <= n) {
        ft[i] += val;
        i += (i & -i);     // Move to next index
    }
}

// Returns sum from index 1 to i
int prefixSum(int i) {
    int s = 0;
    while (i > 0) {
        s += ft[i];
        i -= (i & -i);     // Move to parent
    }
    return s;
}

// Returns sum in range [l, r]
int rangeSum(int l, int r) {
    return prefixSum(r) - prefixSum(l - 1);
}

/*
 Finds the smallest index idx such that:
 prefixSum(idx) >= k

 Assumptions:
 - All values are non-negative
 - Fenwick Tree is built
*/
int findLowerBound(int k) {
    int curr = 0;        // Current index
    int prevSum = 0;     // Sum till curr

    // Largest power of 2 <= n
    int maxLog = log2(n);

    for (int i = maxLog; i >= 0; i--) {
        int next = curr + (1 << i);

        if (next <= n && prevSum + ft[next] < k) {
            curr = next;
            prevSum += ft[curr];
        }
    }

    // curr is the last index where prefix sum < k
    return curr + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example array
    vector<int> arr = {0, 2, 1, 3, 4, 2, 1};
    // Index:              1  2  3  4  5  6

    n = arr.size() - 1;  // because arr is 1-indexed

    // Build Fenwick Tree
    for (int i = 1; i <= n; i++) {
        update(i, arr[i]);
    }

    cout << "Prefix sum till index 5: "
         << prefixSum(5) << "\n";

    cout << "Range sum [2, 5]: "
         << rangeSum(2, 5) << "\n";

    int k = 7;
    int idx = findLowerBound(k);

    cout << "Smallest index with prefix sum >= "
         << k << " is: " << idx << "\n";

    return 0;
}
