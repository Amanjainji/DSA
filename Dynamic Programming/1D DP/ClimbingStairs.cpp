#include<iostream>
#include<vector>
using namespace std;

//Top-Down Approach
int solve(int nStairs,int i,vector<int> &dp){
    //base case
    if(i==nStairs)
        return 1;
    if(i>nStairs){
        return 0;
    }
    if(dp[i]!=-1)
        return dp[i];

    dp[i]= solve(nStairs,i+1,dp) + solve(nStairs,i+2,dp);
    return dp[i];
}

int countDistinctWayToClimb(int n){
    vector<int> dp(n+1,-1);
    return solve(n,0,dp);
}

//bottom up approach
int solve2(int n,vector<int> &dp){
    dp[n]=1;
    for(int i=n-1;i>=0;i--)
        dp[i]= dp[i+1] + dp[i+2];
    return dp[0];
}

int countDistinctWayToClimb2(int n){
    vector<int> dp(n+2,0);
    return solve2(n,dp);
}

//space optimized
int climbStairs(int n) {
        if (n <= 2) 
            return n;

        int prev1 = 2;
        int prev2 = 1;

        for (int i = 2; i < n; i++) {
            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1; 
}
int main(){
    int n=3;
    //cout<<countDistinctWayToClimb2(n)<<endl;
    cout<<climbStairs(n);
}