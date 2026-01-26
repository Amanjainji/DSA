#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int fen[N];
int a[N];

void update(int i, int add) {
    while (i < N) {
        fen[i] += add;
        i += (i & -i);
    }
}

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += fen[i];
        i -= (i & -i);
    }
    return s;
}

int rangeSum(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    int n = 5;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;
    a[5] = 5;

    // Build Fenwick Tree
    for (int i = 1; i <= n; i++) {
        update(i, a[i]);
    }

    cout << sum(5) << endl;        // 15
    cout << rangeSum(2, 4) << endl; // 9

    return 0;
}
