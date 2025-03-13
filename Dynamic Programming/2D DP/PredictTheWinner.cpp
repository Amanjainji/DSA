#include<bits/stdc++.h>
using namespace std;
/*
//Recursion
int solve( vector<int>& nums, int start ,int end){
    if(start==end){
        return nums[start];
    }
   
    //diff
    int diffbyStart=nums[start]-solve(nums,start+1,end);
    int diffbyEnd=nums[end]-solve(nums,start,end-1);
    return max(diffbyStart,diffbyEnd);
}
bool predictTheWinner(vector<int>& nums) {
    return solve(nums, 0,nums.size() - 1)>=0;
}*/
/*
//top down approach
int solveTD( vector<int>& nums, int start ,int end,vector<vector<int>> &dp){
    if(start==end){
        return nums[start];
    }
    if(dp[start][end]!=-1)
        return dp[start][end];
    //diff
    int diffbyStart=nums[start]-solveTD(nums,start+1,end,dp);
    int diffbyEnd=nums[end]-solveTD(nums,start,end-1,dp);
    return dp[start][end]=max(diffbyStart,diffbyEnd);
}
bool predictTheWinner(vector<int>& nums) {
    vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
    return solveTD(nums, 0,nums.size() - 1,dp)>=0;
}
*/

//BOTTOM UP
int solveBU(vector<int> &nums,vector<vector<int>> &dp){
    //base case
    for(int i=0;i<nums.size();i++)
        dp[i][i]=nums[i];

    int i=nums.size();
    for(int start=nums.size()-1;start>=0;--start){
        for(int end=i;end<nums.size();++end){
            int diffbyStart=nums[start]-dp[start+1][end];
            int diffbyEnd=nums[end]-dp[start][end-1];
            dp[start][end]=max(diffbyStart,diffbyEnd);
        }
        --i;
    }
    return dp[0][nums.size()-1];
}
bool predictTheWinner(vector<int>& nums) {
    vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
    return solveBU(nums,dp)>=0;
}

int main(){
    vector<int> nums = {1,5,2};
    cout<<predictTheWinner(nums);
}