#include<iostream>
#include<vector>
using namespace std;

//Top-Bottom Approach APPROACH-1
int solve(vector<int> &cost,int n,vector<int> &dp){
    //base case
    if(n==0)
        return cost[0];
    if(n==1)
        return cost[1];

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]=cost[n] + min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    return dp[n];
}

int minCostClimbingStairs(vector<int> &cost){
    int n=cost.size();
    vector<int> dp(n+1,-1);
    return min(solve(cost,n-1,dp),solve(cost,n-2,dp));    
}

//Bottom-Down Approach APPROACH-2
int minCostClimbingStairs2(vector<int> &cost){
    int n=cost.size();
    //creation of dp array
    vector<int> dp(n+1);

    //base case analysis
    dp[0]=cost[0];
    dp[1]=cost[1];

    for(int i=2;i<=n;i++){
        dp[i]=cost[i]+ min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}

//Space optimization APPROACH-3
int minCostClimbingStairs3(vector<int> &cost){
    int n=cost.size();
    //base case analysis
    int prev2=cost[0];
    int prev1=cost[1];
    for(int i=2;i<n;i++){
        int curr=cost[i]+ min(prev2,prev1);
        prev2=prev1; 
        prev1=curr;
    }
    return min(prev1,prev2);
}


int main(){
    vector<int> cost={10,15,25};
    cout<<minCostClimbingStairs3(cost);
}