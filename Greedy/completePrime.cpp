#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n<2) return false;
    if(n%2==0) return n==2;
    for(long long i=3;i*i<=n;i+=2)
        if(n%i==0) return false;
    return true;
}
bool completePrime(int num) {
    if(isPrime(num)==0) return false;
    int number = num;
    while(number>0){
        if(!isPrime(number)) return false;
        number/=10;
    }

    int tens=1;
    while(tens<=num) tens*=10;
    tens/=10;

    while(tens>1){
        int suff=num%tens;
        if(!isPrime(suff)) return false;
        tens/=10;
    }
    return true;
}

// long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
//     int n=technique1.size();
//     vector<long long> diff;
//     diff.assign(n,0);
//     vector<int> idx(n);

//     for(int i=0;i<n;i++){
//         idx[i]=i;
//         diff[i]=(long long)technique1[i]-technique2[i];
//     }
//     sort(idx.begin(),idx.end(),[&](int a,int b){
//         return diff[a]>diff[b];
//     });
//     long long ans=0;
//     for(int i=0;i<k;i++){
//         int j=idx[i];
//         ans+=technique1[j];
//     }

//     for(int i=k;i<n;i++){
//         int j=idx[i];
//         ans+=max(technique1[j],technique2[j]);
//     }
//     return ans;
// }
int main(){
    cout<<completePrime(100464);
}