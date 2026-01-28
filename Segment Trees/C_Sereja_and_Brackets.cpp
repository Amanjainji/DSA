#include<bits/stdc++.h>
using namespace std;

class bracket{
    public: 
    int open;
    int close;
    int full;
    bracket() {          
        open = close = full = 0;
    }

    bracket(int o,int c,int f){
        open=o;
        close=c;
        full=f;
    }
};
void build(int ind, int low, int high, bracket seg[], string &s){
    if(low == high){
        if(s[low] == '(')
            seg[ind] = bracket(1,0,0);
        else
            seg[ind] = bracket(0,1,0);
        return;
    }

    int mid = (low + high) / 2;
    build(2*ind+1, low, mid, seg, s);
    build(2*ind+2, mid+1, high, seg, s);

    int match = min(seg[2*ind+1].open, seg[2*ind+2].close);

    int open  = seg[2*ind+1].open  + seg[2*ind+2].open  - match;
    int close = seg[2*ind+1].close + seg[2*ind+2].close - match;
    int full  = seg[2*ind+1].full  + seg[2*ind+2].full  + match;

    seg[ind] = bracket(open, close, full);
}


bracket query(int ind, int low, int high, int l, int r, bracket seg[]) {

    // no overlap
    if (high < l || low > r) {
        return bracket(0,0,0);
    }

    // complete overlap
    if (low >= l && high <= r) {
        return seg[ind];
    }

    // partial overlap
    int mid = (low + high) / 2;
    bracket left = query(2*ind+1, low, mid, l, r, seg);
    bracket right = query(2*ind+2, mid+1, high, l, r, seg);

    int full = min(left.open, right.close);
    int open = left.open + right.open - full;
    int close = left.close + right.close - full;

    return bracket(open, close, left.full + right.full + full);
}


int main(){
    string s;
    cin>>s;
    int n=s.size();
    bracket seg[4*n];
    build(0, 0, n-1, seg, s);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l-1,r-1,seg).full*2<<endl;
    }
}