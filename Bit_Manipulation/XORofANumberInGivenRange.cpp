#include<bits/stdc++.h>
using namespace std;

int XORtillN(int N){
    if(N%4==0)
        return N;
    else if(N%4==1)
        return 1;
    else if(N%4==2)
        return N+1;
    else
        return 0;
}

int XORinRange(int l,int r){
    return XORtillN(l-1)^XORtillN(r);
}

int main(){
    cout<<XORinRange(4,6);
}

