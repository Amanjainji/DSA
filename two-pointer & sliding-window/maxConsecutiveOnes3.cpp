#include<bits/stdc++.h>
using namespace std;

/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
*/

//brute force TC - O(N^2)
int longestOnes(vector<int>& nums, int k) {
    int n=nums.size();
    int maxlen=0;
    for(int i=0;i<n;i++){
        int zeros=0;
        for(int j=i;j<n;j++){
            if(nums[j]==0)
                zeros++;
            
            if(zeros<=k)
                maxlen=max(maxlen,j-i+1);
            else
                break;
        }
    }
    return maxlen;
}

//two pointer TC- O(2N)
int longestOnes1(vector<int>& nums, int k) {
    int n=nums.size();
    int l=0,r=0,zeros=0,maxlen=0;
    while(r<n){
        if(nums[r]==0)
            zeros++;
            
        while(zeros>k){
            if(nums[l]==0)
                zeros--;
            l++;
        }
        
        maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;
}

//sliding window TC - O(N)
int longestOnes2(vector<int>& nums, int k) {
    int n=nums.size();
    int l=0,r=0,zeros=0,maxlen=0;
    while(r<n){
        if(nums[r]==0)
            zeros++;
            
        if(zeros>k){
            if(nums[l]==0)
                zeros--;
            l++;
        }
        if(zeros<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

int main(){
    vector<int> nums={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    cout<<longestOnes1(nums,k);
}
