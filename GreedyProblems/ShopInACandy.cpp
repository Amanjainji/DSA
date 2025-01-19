/*
In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided to you. You are now provided with an attractive offer.
For every candy you buy from the store and get K other candies ( all are different types ) for free. Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the n different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the n different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get k other candies for free.

Input: n = 4, k = 2, candies[] = {3 2 1 4}
Output: min- 3$  max- 7$
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[],int n,int k){
    sort(candies,candies+n);
    vector<int> ans;

    int mini=0;
    int buy=0;
    int free=n-1;
    while(buy<=free){
        mini=mini+candies[buy++];
        free=free-k;
    }

    ans.push_back(mini);

    int maxi=0;
    buy=n-1;
    free=0;
    while(buy>=free){
        maxi=maxi+candies[buy--];
        free=free+k;
    }
    ans.push_back(maxi);
    return ans;
}

int main(){
    int candies[]={3,2,1,4};
    vector<int> k=candyStore(candies,4,2);
    for(auto i:k){
        cout<<i<<" ";
    }
}

