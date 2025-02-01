/*
LEETCODE Q96
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:

Input: n = 3
Output: 5

Example 2:

Input: n = 1
Output: 1
*/


//Hint - one line answer using catalan number
#include<bits/stdc++.h>
using namespace std;

//Recursive
int numTrees(int n) {
    if(n<=1)
        return 1;
    
    int ans=0;
    //think i as root node
    for(int i=1;i<=n;i++){
        ans+=numTrees(i-1)*numTrees(n-i);
    }
    return ans;
}

//Recursive + memoization
int solve(int n,vector<int> &dp) {
    if(n<=1)
        return 1;

    if(dp[n]!=-1)
        return dp[n];
    
    int ans=0;
    //think i as root node
    for(int i=1;i<=n;i++){
        ans+=solve(i-1,dp)*solve(n-i,dp);
    }
    return dp[n]=ans;
}

int numTreesMem(int n){
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}

//Tabulation
int numTreesTab(int n){
    vector<int> dp(n+1,0);
    dp[0]=dp[1]=1;

    //i -> number of nodes
    for(int i=2;i<=n;i++){
        //j->root->node
        for(int j=1;j<=i;j++){
            dp[i]+= dp[j-1]* dp[i-j];
        }
    }
    return dp[n];
}


//Catalan number method
int numTreesCN(int n) {
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans = ans * (2 * n - i) / (i + 1);     //i+1 because denominator can't be zero  (2n n)
    }
    return ans / (n + 1);
}

int main(){
    int n=3;
    cout<<numTreesCN(19);
}


