#include<bits/stdc++.h>
using namespace std;

//TC - O(root(N) x log(N))
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
int main(){
    vector<int> k=primeFactors(780);
    for(auto i:k)
        cout<<i<<endl;
}