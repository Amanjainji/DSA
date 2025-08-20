#include<bits/stdc++.h>
using namespace std;

int countbits1(int n){
    int cnt=0;
    while(n>1){
        cnt+=n&1;
        n=n>>1;
    }
    if(n==1) cnt+=1;
    return cnt;
}

int countbits2(int n){
    int cnt=0;
    while(n!=0){
        n=n&(n-1);
        cnt++;
    }
    return cnt;
}

int main(){
    cout<<countbits1(14)<<endl;
    cout<<countbits2(16)<<endl;
}