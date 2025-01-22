#include<bits/stdc++.h>
using namespace std;

/*
Given a number n, find the minimum number of perfect squares (square of an integer) that sum up to n. 

Examples:

Input: n = 6
Output: 3
Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6 

Expected Time Complexity: O(n * sqrt(n))
Expected Space Complexity: O(n)
*/

//recursive
int solve(int n){
    if(n==0)
        return 0;
    int ans=n;
    for(int i=1;i*i<=n;i++){
        int square=i*i;
        ans=min(ans,1+solve(n-square));
    }
    return ans;
}

int minSquares(int n){
    return solve(n);
}

//recursive + memoization
int solve2(int n,vector<int> &dp){
    if(n==0)
        return 0;
    
    if(dp[n]!=-1)
        return dp[n];
    int ans=n;
    for(int i=1;i*i<=n;i++){
        int square=i*i;
        ans=min(ans,1+solve2(n-square,dp));
    }
    dp[n]= ans;
    return dp[n];
}

int minSquares2(int n){
    vector<int> dp(n+1,-1);
    return solve2(n,dp);
}

//tabulation
int minSquares3(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            int square=j*j;
            if(i-square>=0)
                dp[i]=min(dp[i],1+dp[i-square]);
        }
    }
    return dp[n];
}

int main(){
    cout<<minSquares3(40);
}