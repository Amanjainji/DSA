#include <bits/stdc++.h>
using namespace std;

const int N = 100005;   // size of array (change as needed)
int fen[N];

// Add `add` to index `i`
void update(int i, int add) {
    while (i < N) {
        fen[i] += add;
        i += (i & -i);   // move to next responsible index
    }
}

// Returns sum from 1 to i
int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += fen[i];
        i -= (i & -i);   // move to parent
    }
    return s;
}

// Returns sum from l to r
int rangeSum(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    // Example usage:
    update(1, 5);
    update(3, 7);
    update(5, 2);

    cout << sum(5) << endl;        // sum from 1 to 5
    cout << rangeSum(2, 5) << endl; // sum from 2 to 5

    return 0;
}
