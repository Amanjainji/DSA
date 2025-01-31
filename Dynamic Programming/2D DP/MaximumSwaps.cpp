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
int solve(vector<int> &nums1, vector<int> &nums2 ,int index, bool swapped){
    //base case
    if(index==nums1.size())
        return 0;
    
    int ans= INT_MAX;

    int prev1= nums1[index-1];
    int prev2=nums2[index-1];

    //catch
    if(swapped)   // we are not really swapping in arrays just counting swaps
        swap(prev1,prev2);
    
    //no swap -  no need of swap already strictly increasing
    if(nums1[index]>prev1 && nums2[index]>prev2)
        ans=min(ans,solve(nums1,nums2,index+1,0));
    
    //swap
    if(nums1[index]>prev2 && nums2[index]>prev1)
        ans=min(ans,1+solve(nums1,nums2,index+1,1));

    return ans;
}

int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    return solve(nums1,nums2,1,0);
}

//Memoization
int solveMem(vector<int> &nums1, vector<int> &nums2 ,int index, bool swapped,vector<vector<int>> &dp){
    //base case
    if(index==nums1.size())
        return 0;
    
    int ans= INT_MAX;

    int prev1= nums1[index-1];
    int prev2=nums2[index-1];

    if(dp[index][swapped]!=-1)
        return dp[index][swapped];

    //catch
    if(swapped)   // we are not really swapping in arrays just counting swaps
        swap(prev1,prev2);
    
    //no swap -  no need of swap already strictly increasing
    if(nums1[index]>prev1 && nums2[index]>prev2)
        ans=min(ans,solveMem(nums1,nums2,index+1,0,dp));
    
    //swap
    if(nums1[index]>prev2 && nums2[index]>prev1)
        ans=min(ans,1+solveMem(nums1,nums2,index+1,1,dp));

    return dp[index][swapped]=ans;
}

int minSwapMem(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    vector<vector<int>> dp(nums1.size()+1,vector<int>(2,-1));
    return solveMem(nums1,nums2,1,0,dp);
}

//Tabulation
int minSwapTab(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<vector<int>> dp(n+1, vector<int>(2, INT_MAX));

    // Base case: No swaps needed at the last index
    dp[n-1][0] = 0;
    dp[n-1][1] = 0;

    for (int index = n-2; index >= 0; index--) {
        for (int swapped = 0; swapped <= 1; swapped++) {
            int ans = INT_MAX;
            int prev1 = nums1[index];
            int prev2 = nums2[index];

            if (swapped) 
                swap(prev1, prev2);

            // No swap case
            if (nums1[index+1] > prev1 && nums2[index+1] > prev2)
                ans = min(ans, dp[index+1][0]);

            // Swap case
            if (nums1[index+1] > prev2 && nums2[index+1] > prev1)
                ans = min(ans, 1 + dp[index+1][1]);

            dp[index][swapped] = ans;
        }
    }
    return min(dp[0][0], 1+dp[0][1]);
}

int minSwapSO(vector<int> nums1, vector<int> nums2) {
    int n = nums1.size();
    int swap=0;
    int noswap=0;
    int currswap=0;
    int currnoswap=0;

    for (int index = n-1; index >= 1; index--) {
        for (int swapped = 1; swapped >=0; swapped--) {
            int ans = INT_MAX;
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];

            if (swapped) {
                int temp=prev1;
                prev1=prev2;
                prev2=temp;
            }

            // No swap case
            if (nums1[index] > prev1 && nums2[index] > prev2)
                ans = noswap;

            // Swap case
            if (nums1[index] > prev2 && nums2[index] > prev1)
                ans = min(ans, 1 +swap);

            if(swapped)
                currswap=ans;
            else
                currnoswap=ans;
        }
        swap=currswap;
        noswap=currnoswap;
    }
    return min(swap,noswap);
}

int main(){
    vector<int> nums1 = {1,3,5,4}, nums2 = {1,2,3,7};
    cout<<minSwapSO(nums1,nums2);
}