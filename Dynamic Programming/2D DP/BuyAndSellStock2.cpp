/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/
#include<bits/stdc++.h>
using namespace std;

//recursive
int solve(vector<int>& prices,int buy,int index){
    int n=prices.size();
    if(index>=n)
        return 0;
    
    int profit=0;
    if(buy){
        int buyKaro=-prices[index]+solve(prices,0,index+1);
        int skipKaro=0+solve(prices,1,index+1);
        profit=max(buyKaro,skipKaro);
    }
    else{
        int sellKaro=prices[index]+solve(prices,1,index+1);
        int skipKaro=0+solve(prices,0,index+1);
        profit=max(sellKaro,skipKaro);
    }
    return profit;
}
int maxProfit(vector<int>& prices) {
   return solve(prices,1,0);
}

//memoization
int solveMem(vector<int>& prices,int buy,int index,vector<vector<int>> &dp){
    int n=prices.size();
    if(index>=n)
        return 0;
    
    if(dp[index][buy]!=-1)
        return dp[index][buy];

    int profit=0;
    if(buy){
        int buyKaro=-prices[index]+solveMem(prices,0,index+1,dp);
        int skipKaro=0+solveMem(prices,1,index+1,dp);
        profit=max(buyKaro,skipKaro);
    }
    else{
        int sellKaro=prices[index]+solveMem(prices,1,index+1,dp);
        int skipKaro=0+solveMem(prices,0,index+1,dp);
        profit=max(sellKaro,skipKaro);
    }
    return dp[index][buy]=profit;
}
int maxProfitMem(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return solveMem(prices,1,0,dp);
}

//Tabulation
int maxProfitTab(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy){
                int buyKaro=-prices[index]+dp[index+1][0];
                int skipKaro=0+dp[index+1][1];
                profit=max(buyKaro,skipKaro);
            }
            else{
                int sellKaro=prices[index]+dp[index+1][1];
                int skipKaro=0+dp[index+1][0];
                profit=max(sellKaro,skipKaro);
            }
            dp[index][buy]=profit;
        }
    }
    return dp[0][1];
}

//Space optimization
int maxProfitSO(vector<int>& prices) {
    int n=prices.size();
    vector<int> curr(2,0);
    vector<int> next(2,0);

    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy){
                int buyKaro=-prices[index]+next[0];
                int skipKaro=0+next[1];
                profit=max(buyKaro,skipKaro);
            }
            else{
                int sellKaro=prices[index]+next[1];
                int skipKaro=0+next[0];
                profit=max(sellKaro,skipKaro);
            }
            curr[buy]=profit;
        }
        next=curr;
    }
    return next[1];
}

int main(){
    vector<int> p= {7,1,5,3,6,4};
    cout<<maxProfitSO(p);
}