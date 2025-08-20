#include<bits/stdc++.h>
using namespace std;

//brute force
vector<int> primeFactors(int n){
    vector<int> ans;
    for(int i=2;i<pow(n,0.5);i++){
        if(n%i==0){
            ans.push_back(i);
            while(n%i==0)
                n=n/i;
        }      
    }
    if(n>1) ans.push_back(n);
    return ans;
}

//appropriate method for queries assuming n<=100000
int primeFactors2(int n){
    vector<int> spf(100001);
    for(int i=0;i<100001;i++){
        spf[i]=i;
    }
    for(int i=2;i*i<100001;i++){
        if(spf[i]==i){
            for(int j=i*i;j<100001;j=j+i){
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
    return spf[n];
}


int main(){
    //vector<int> k=primeFactors(780);
    //cout<<k[0]<<endl;
    cout<<primeFactors2(13);
}