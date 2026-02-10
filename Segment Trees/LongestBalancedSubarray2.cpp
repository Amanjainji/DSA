#include <bits/stdc++.h>
using namespace std;

// Global arrays for the Segment Tree (0-based indexing)
int min_seg[400005];
int max_seg[400005];
int lazy[400005];

// Reset function to clear globals for multiple test cases (if needed)
void reset_tree(int n) {
    for(int i=0; i<=4*n; i++) {
        min_seg[i] = 0;
        max_seg[i] = 0;
        lazy[i] = 0;
    }
}

// Build segment tree
void build(const vector<int>& arr, int ind, int low, int high) {
    lazy[ind] = 0; // Initialize lazy
    if (low == high) {
        min_seg[ind] = arr[low];
        max_seg[ind] = arr[low];
        return;
    }

    int mid = (low + high)/2;
    build(arr, 2 * ind + 1, low, mid);
    build(arr, 2 * ind + 2, mid + 1, high);

    min_seg[ind] = min(min_seg[2 * ind + 1], min_seg[2 * ind + 2]);
    max_seg[ind] = max(max_seg[2 * ind + 1], max_seg[2 * ind + 2]);
}

// Range update: add val to range [l, r]
void rangeUpdate(int ind, int low, int high, int l, int r, int val) {
    // Step 1: Push Lazy
    if (lazy[ind] != 0) {
        min_seg[ind] += lazy[ind];
        max_seg[ind] += lazy[ind];

        if (low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    // Step 2: No Overlap
    if (r < low || l > high)
        return;

    // Step 3: Complete Overlap
    if (low >= l && high <= r) {
        min_seg[ind] += val;
        max_seg[ind] += val;

        if (low != high) {
            lazy[2 * ind + 1] += val;
            lazy[2 * ind + 2] += val;
        }
        return;
    }

    // Step 4: Partial Overlap
    int mid = (low + high) >> 1;
    rangeUpdate(2 * ind + 1, low, mid, l, r, val);
    rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);

    min_seg[ind] = min(min_seg[2 * ind + 1], min_seg[2 * ind + 2]);
    max_seg[ind] = max(max_seg[2 * ind + 1], max_seg[2 * ind + 2]);
}

// Find the LAST index k in [start_limit, n-1] such that value[k] == 0
int query(int ind, int low, int high, int start_limit) {
    // Resolve lazy
    if (lazy[ind] != 0) {
        min_seg[ind] += lazy[ind];
        max_seg[ind] += lazy[ind];
        if (low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    // Pruning: Range is completely before start_limit
    if (high < start_limit) return -1;

    // Pruning: 0 is impossible in this range
    if (min_seg[ind] > 0 || max_seg[ind] < 0) return -1;

    // Leaf node
    if (low == high) {
        return (min_seg[ind] == 0) ? low : -1;
    }

    int mid = (low + high) >> 1;
    
    // Search Right Child First (to find the rightmost index)
    int res = query(2 * ind + 2, mid + 1, high, start_limit);
    
    if (res != -1) return res;
    
    // If not found in right, search Left Child
    return query(2 * ind + 1, low, mid, start_limit);
}

int sgn(int x){
    return (x % 2) == 0 ? 1 : -1;
}

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        reset_tree(n); 

        map<int, queue<int>> occurrences;
        int len = 0;
        vector<int> prefix_sum(n, 0);

        prefix_sum[0] = sgn(nums[0]);
        occurrences[nums[0]].push(1);   //occurrences stores positions of each value.(1-based indexing)

        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1];
            auto& occ = occurrences[nums[i]];
            if (occ.empty()) {
                prefix_sum[i] += sgn(nums[i]);
            }
            occ.push(i + 1);
        }

        build(prefix_sum, 0, 0, n - 1);

        for (int i = 0; i < n; i++) {
            // QUERY
            // We need to find the furthest index >= (i + len) with value 0
            // Since our tree is 0-based, the returned index 'idx' is the actual array index.
            // Length of subarray nums[i...idx] is (idx - i + 1).
            int idx = query(0, 0, n - 1, i + len);
            
            if (idx != -1) {
                len = max(len, idx - i + 1);
            }

            int next_pos = n + 1;   // so next_pos-2 = n-1 index (end of the array)
            occurrences[nums[i]].pop();
            if (!occurrences[nums[i]].empty()){
                next_pos = occurrences[nums[i]].front();
            }

            // UPDATE
            // Original logic: update range [i + 1, next_pos - 1] (1-based indices)
            // 0-based conversion: 
            // Start: (i + 1) - 1  => i
            // End:   (next_pos - 1) - 1 => next_pos - 2
            if (i <= next_pos - 2) {
                rangeUpdate(0, 0, n - 1, i, next_pos - 2, -sgn(nums[i]));
            }
        }

        return len;
    }
};

/*
Why min/max?

Because when searching for value 0:

if(min_seg > 0 || max_seg < 0)
    → impossible to contain 0

We prune entire segment instantly 

*/