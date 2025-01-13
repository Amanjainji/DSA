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

    dp[i]= solve(nStairs,i+1,dp) + solve(nStairs,i+2,dp);
    return dp[i];
}

int countDistinctWayToClimb(int n){
    vector<int> dp(n+1,-1);
    return solve(n,0,dp);
}


//space optimized
int climbStairs(int n) {
        if (n <= 3) 
            return n;

        int prev1 = 3;
        int prev2 = 2;

        for (int i = 3; i < n; i++) {
            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1; 
}
int main(){
    int n=5;
    cout<<countDistinctWayToClimb(n)<<endl;
    cout<<climbStairs(n);
}