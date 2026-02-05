#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MAXN = 1000005;
int seg[4 * MAXN]; 

void addInTree(int ind, int low, int high, int pos, int val) {
    if (low == high) {
        seg[ind] += val;
        return;
    }

    int mid = (low + high) / 2;
    if (pos <= mid)
        addInTree(2 * ind + 1, low, mid, pos, val);
    else
        addInTree(2 * ind + 2, mid + 1, high, pos, val);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int query(int ind, int low, int high, int l, int r) {
    // No overlap
    if (high < l || low > r) {
        return 0;
    }

    // Complete overlap
    if (low >= l && high <= r) {
        return seg[ind];
    }

    // Partial overlap
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);

    return left + right;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    // --- Step 1: Coordinate Compression ---
    // We map large values (e.g., 10^9) to small range [0, n-1]
    set<int> s;
    for(int x : a) {
        s.insert(x);
    }

    // Copy back to vector b
    vector<int> b;
    for(int x : s) {
        b.push_back(x);
    }
    
    // Replace original values with their rank
    for(int i=0; i<n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    // --- Step 2: Calculate "Right Smaller" ---
    // We go from Right to Left. 
    // For each number, we ask: "How many numbers seen so far are smaller than me?"
    vector<long long> right_smaller(n);
    for(int i = n-1; i >= 0; i--) {
        // Query range [0, a[i]-1] (strictly smaller)
        if(a[i] > 0)
            right_smaller[i] = query(0, 0, n, 0, a[i] - 1);
        else
            right_smaller[i] = 0;
            
        // Add current number to the tree
        addInTree(0, 0, n, a[i], 1);
    }

    // --- Step 3: Calculate "Left Greater" ---
    // Reset the tree (fill with 0)
    for(int i=0; i<4*MAXN; i++) seg[i] = 0;
    
    vector<long long> left_greater(n);
    for(int i = 0; i < n; i++) {
        // Query range [a[i]+1, n] (strictly greater)
        left_greater[i] = query(0, 0, n, a[i] + 1, n);
            
        // Add current number to the tree
        addInTree(0, 0, n, a[i], 1);
    }

    long long ans = 0;
    for(int i=0; i<n; i++) {
        ans += left_greater[i] * right_smaller[i];
    }
    
    cout << ans << endl;
    
    return 0;
}

/*
#include <iostream>
#include <vector>

using namespace std;

const int MAX_VAL = 1000005; 
int seg[4 * MAX_VAL]; 

// addInTree function: Adds 'val' to the count at 'pos'
// pos represents the actual number value (e.g., number 5 is at index 5)
void addInTree(int ind, int low, int high, int pos, int val) {
    if (low == high) {
        seg[ind] += val; 
        return;
    }

    int mid = (low + high) / 2;
    if (pos <= mid)
        addInTree(2 * ind + 1, low, mid, pos, val);
    else
        addInTree(2 * ind + 2, mid + 1, high, pos, val);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

// Query function: Returns sum of counts in range [l, r]
int query(int ind, int low, int high, int l, int r) {
    if (high < l || low > r) return 0;       // No overlap
    if (low >= l && high <= r) return seg[ind]; // Complete overlap

    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);

    return left + right;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }

    vector<long long> right_smaller(n);
    vector<long long> left_greater(n);

    // --- Pass 1: Right to Left (Count smaller elements to the right) ---
    for (int i = n - 1; i >= 0; i--) {
        // Query range [0, a[i]-1] -> Count numbers strictly smaller than current value
        if (a[i] > 0)
            right_smaller[i] = query(0, 0, MAX_VAL, 0, a[i] - 1);
        else
            right_smaller[i] = 0;

        // Add current value a[i] to the tree
        addInTree(0, 0, MAX_VAL, a[i], 1);
    }

    for (int i = 0; i < 4 * MAX_VAL; i++) seg[i] = 0;

    // --- Pass 2: Left to Right (Count greater elements to the left) ---
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        // Query range [a[i]+1, MAX_VAL] -> Count numbers strictly greater than current value
        left_greater[i] = query(0, 0, MAX_VAL, a[i] + 1, MAX_VAL);

        addInTree(0, 0, MAX_VAL, a[i], 1);
        
        ans += left_greater[i] * right_smaller[i];
    }

    cout << ans << endl;

    return 0;
}
*/