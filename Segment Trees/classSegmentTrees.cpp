#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
    
    const int *a;
    vector<int> seg;    //always 4n capacity

    public:
        SegmentTree(const int *arr,int n){
            seg.resize(4*n);
            a=arr;
        }
// Build the segment tree
void build(int ind, int low, int high) {
    if (low == high) {
        seg[ind] = a[low];
        return;
    }

    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);

    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

// Range maximum query
int query(int ind, int low, int high, int l, int r) {
    // complete overlap
    if (low >= l && high <= r) {
        return seg[ind];
    }

    // no overlap
    if (high < l || low > r) {
        return INT_MIN;
    }

    // partial overlap
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);

    return max(left, right);
}

void update(int ind, int low, int high, int i, int val) {
    if (low == high) {
        seg[ind] = val;
        return;
    }

    int mid = (low + high) / 2;
    if (i <= mid)
        update(2 * ind + 1, low, mid, i, val);
    else
        update(2 * ind + 2, mid + 1, high, i, val);

    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}
};


int main() {
    int n;
    cout<<"Enter Array size: ";
    cin >> n;
    cout<<"Enter Elements: ";
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegmentTree obj= SegmentTree(a,n);

    cout<<"Building Tree...."<<endl;

    obj.build(0, 0, n - 1);
    cout<<"Tree builded successfully...."<<endl;
    cout<<"Enter No. of Queries: ";
    int q;
    cin >> q;
    cout<<"Enter Queries: "<<endl;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << obj.query(0, 0, n - 1, l, r) << endl;
    }

    //if update query
    cout<<"Enter No. of updates: ";
    int updateQ;
    cin>>updateQ;
    while(updateQ--){
        int i,val;  //i = index to update
        cin>>i>>val;
        obj.update(0,0,n-1,i,val);
    }

    cout<<"Enter No. of Queries: ";
    int q2;
    cin >> q2;
    cout<<"Enter Queries: "<<endl;
    while (q2--) {
        int l, r;
        cin >> l >> r;
        cout << obj.query(0, 0, n - 1, l, r) << endl;
    }

    return 0;
}

