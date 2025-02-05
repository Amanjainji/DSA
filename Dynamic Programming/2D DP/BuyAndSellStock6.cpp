#include<bits/stdc++.h>
using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

*/


//procedure - buy and sell stock 2 case just change index+2 in sell for cooldown
int maxProfitTab(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy){
                int buyKaro=-prices[index]+dp[index+1][0];
                int skipKaro=0+dp[index+1][1];
                profit=max(buyKaro,skipKaro);
            }
            else{
                int sellKaro=prices[index]+dp[index+2][1];
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
    vector<int> Next(2,0);

    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy){
                int buyKaro=-prices[index]+next[0];
                int skipKaro=0+next[1];
                profit=max(buyKaro,skipKaro);
            }
            else{
                int sellKaro=prices[index]+Next[1];
                int skipKaro=0+next[0];
                profit=max(sellKaro,skipKaro);
            }
            curr[buy]=profit;
        }
        Next=next;
        next=curr;
    }
    return next[1];
}

int main(){
    vector<int> prices = {1,2,3,0,2};
    cout<<maxProfitTab(prices);
}