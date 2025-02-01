#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].
*/

int longestSubsequence(vector<int>& arr, int difference) {
    unordered_map<int,int> dp;  //us element tk -> APlength
    int ans=0;
    for(int i=0;i<arr.size();i++){
        int temp=arr[i]-difference;
        int tempAns=0;

        //check answer exist for temp already or not
        if(dp.count(temp))
            tempAns=dp[temp];
        
        //current answer update
        dp[arr[i]]=1+tempAns;

        //ans update
        ans=max(ans,dp[arr[i]]);
    } 
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4}; 
    int difference = 1;
    cout<<longestSubsequence(arr,difference);
}