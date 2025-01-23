#include<bits/stdc++.h>
using namespace std;

//recursive
int countDerangements( int n) {
    //base case
    if(n==1)
        return 0;
    if (n==2)
        return 1;
    int ans=(n-1)*(countDerangements(n-1) + countDerangements(n-2));
    return ans;
}


//Top-Down approach (Memoization)
int solveMem(int n,vector<int> &dp){
    //base case
    if(n==1)
        return 0;
    if (n==2)
        return 1;

    if(dp[n]!=-1)
        return dp[n];
    
    dp[n]=(n-1)*(solveMem(n-1,dp) + solveMem(n-2,dp));
    return dp[n];
}

int countDerangements2(int n) {
    vector<int> dp(n+1,-1);
    return solveMem(n,dp);
}

//Bottom Up approach - Tabulation
int countDerangements3(int n) {
    vector<int> dp(n+1,0);
    //base case
    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;i++){
        dp[i]=(i-1)*(dp[i-1] + dp[i-2]);
    } 
    return dp[n];
}

//space optimization
int countDerangements4(int n) {
    //base case handling
    int prev2=0;
    int prev1=1;
    if(n<=1)
        return 0;

    for(int i=3;i<=n;i++){
        int ans=(i-1)*(prev1 + prev2);
        prev2=prev1;
        prev1=ans;
    } 
    return prev1;
}

int main(){
    cout<<countDerangements4(1)<<endl;
}