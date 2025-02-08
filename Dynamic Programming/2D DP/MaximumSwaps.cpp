#include<bits/stdc++.h>
using namespace std;

/*
You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.

An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

 

Example 1:

Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
Output: 1
Explanation: 
Swap nums1[3] and nums2[3]. Then the sequences are:
nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
which are both strictly increasing.
*/


/*
Algo
1)Insert -1 in the arrays on index 0 so we can track previous
2)Store prev element of both array
3) if previous elements were swapped ,then swapped =1 and interchange both previous to maintain array after swapped
4)Call for no-swap condn and swap condn
*/
int solve(vector<int> &nums1, vector<int> &nums2 ,int i, int p1,int p2){
    //base case
    if(i==nums1.size())
        return 0;
    
    int swap= INT_MAX;
    int noswap=INT_MAX;
     //swap
     if(p1<nums2[i] && p2<nums2[i])
        swap=1+solve(nums1,nums2,i+1,nums1[i],nums2[i]);
    
     //no swap -  no need of swap already strictly increasing
    if(p1<nums1[i] && p2<nums2[i])
        noswap=solve(nums1,nums2,i+1,nums2[i],nums1[i]);
    return min(swap,noswap);
}

int minSwap(vector<int>& nums1, vector<int>& nums2) {
    return solve(nums1,nums2,0,-1,-1);
}

//Memoization
int solveMem(vector<int> &nums1, vector<int> &nums2 ,int i, int p1,int p2,vector<vector<int>> &dp,bool isswap){
    //base case
    if(i==nums1.size())
        return 0;
    
    int swap= INT_MAX;
    int noswap=INT_MAX;
    if(dp[i][isswap]!=-1)
        return dp[i][isswap];
     //swap
    if(p1<nums2[i] && p2<nums1[i])
        swap=1+solveMem(nums1,nums2,i+1,nums1[i],nums2[i],dp,1);
    
     //no swap -  no need of swap already strictly increasing
    if(p1<nums1[i] && p2<nums2[i])
        noswap=solveMem(nums1,nums2,i+1,nums2[i],nums1[i],dp,0);
    return dp[i][isswap]= min(swap,noswap);
}

int minSwapMem(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> dp(nums1.size()+1,vector<int>(2,-1));
    return solveMem(nums1,nums2,0,-1,-1,dp,0);
}

//Tabulation
int minSwapTab(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    int n = nums1.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for (int i=n-1; i >= 1; i--) {
        for (int j= 1; j>=0; j--) {
            int p1 = nums1[i-1];
            int p2 = nums2[i-1];

            if(j)
                swap(p1,p2);
            //swap
            int swap=INT_MAX,noswap=INT_MAX;
            if(p1<nums2[i] && p2<nums1[i])
                swap=1+dp[i+1][1];

            //no swap -  no need of swap already strictly increasing
            if(p1<nums1[i] && p2<nums2[i])
                noswap=dp[i+1][0];
            dp[i][j]= min(swap,noswap);

        }
    }
    return dp[1][0];    //1 bacuse adding of -1 in array
}

int minSwapSO(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    int n = nums1.size();
    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for (int i=n-1; i >= 1; i--) {
        for (int j= 1; j>=0; j--) {
            int p1 = nums1[i-1];
            int p2 = nums2[i-1];

            if(j)
                swap(p1,p2);
            //swap
            int swap=INT_MAX,noswap=INT_MAX;
            if(p1<nums2[i] && p2<nums1[i])
                swap=1+next[1];

            //no swap -  no need of swap already strictly increasing
            if(p1<nums1[i] && p2<nums2[i])
                noswap=next[0];
            curr[j]= min(swap,noswap);
        }
        next=curr;
    }
    return next[0];    //1 bacuse adding of -1 in array
}

int main(){
    vector<int> nums1 = {1,3,5,4}, nums2 = {1,2,3,7};
    cout<<minSwapSO(nums1,nums2);
}