#include<iostream>
#include<vector>
using namespace std;

//Top down approach
int fibonacci(int n,vector<int> &dp){
    if(n==0 || n==1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
    return dp[n];
}

//Bottom down approach
int fibonacci2(int n){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

//Space Optimization Approach
int fibonacci3(int n){
    int prev1=1;
    int prev2=0;
    if(n==0)
        return 0;
    for(int i=2;i<=n;i++){
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}


int main(){
    int n=6;
    vector<int> dp(n+1,-1); 
    cout<<fibonacci(n,dp)<<endl;
    cout<<fibonacci2(n)<<endl;
    cout<<fibonacci3(n);
}