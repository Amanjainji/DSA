#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, Q;
    cin >> n >> Q;

    // diff size = n+2 so we can subtract at R+1
    vector<long long> diff(n+2,0);  //assuming the array of 0s

    for(int i=0; i<Q; i++){
        int L, R;
        cin >> L >> R;
        diff[L] += 1;   //update values
        diff[R+1] -= 1;
    }

    // build final array using prefix sum
    for(int i=1; i<=n; i++){
        diff[i] += diff[i-1];
        cout << diff[i] << " ";
    }
    cout << "\n";

    /*
    5
    2
    1 3
    2 4
    */
}