/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
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
                int sellKaro=prices[index]+next[1]-fee;
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
    vector<int> p= {1,3,2,8,4,9};
    cout<<maxProfit(p,2);
}