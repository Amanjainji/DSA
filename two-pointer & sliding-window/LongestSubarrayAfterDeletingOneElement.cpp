#include<bits/stdc++.h>
using namespace std;

/*
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
*/

//brute force
int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int zeros=0,ones=0;
            for(int j=i;j<n;j++){
                if(nums[j]==1)  ones++;
                if(nums[j]==0)  zeros++;
                if(zeros<=1){
                    if(ones)
                        ans=max(ans,j-i+1);
                }
                else
                    break;
            }
        }
    return (ans==0)?0:ans-1;
}

//two pointer
int longestSubarray1(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int l=0,r=0,zeros=0,ones=0;
        while(r<n){
            if(nums[r]==0) zeros++;
            else ones++;

            while(zeros>1){
                if(nums[l]==0) zeros--;
                else ones--;
                l++;
            }
            if(ones)
                ans=max(ans,r-l+1);
            r++;
        }
    return (ans==0)?0:ans-1;
}

//sliding window
int longestSubarray2(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int l=0,r=0,zeros=0,ones=0;
        while(r<n){
            if(nums[r]==0) zeros++;
            else ones++;

            if(zeros>1){
                if(nums[l]==0) zeros--;
                else ones--;
                l++;
            }
            if(ones && zeros<=1)
                ans=max(ans,r-l+1);
            r++;
        }
    return (ans==0)?0:ans-1;
}

int main(){
    vector<int> nums={1,1,0,1};
    cout<<longestSubarray1(nums);
}