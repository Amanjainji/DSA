// C++ program to find maximum
// Sum Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;

//recursive
int ans=INT_MIN;
int maxSum(int i,vector<int> &arr,int prev){
    if(i==arr.size())
        return 0;

    int includeSum=0;
    if(prev==-1 || arr[i]>arr[prev]){
        includeSum=arr[i]+maxSum(i+1,arr,i);
    }
    int excludeSum=maxSum(i+1,arr,prev);

    return max({ans,includeSum,excludeSum});
}


// memoization
int maxSum2(int i, int prev, vector<int>& arr, vector<vector<int>>& dp) {
    if (i == arr.size())
        return 0;

    if (dp[i][prev + 1] != -1)
        return dp[i][prev + 1];     //prev+1 because of -1

    // Include
    int includeSum = 0;
    if (prev == -1 || arr[i] > arr[prev]) {
        includeSum = arr[i] + maxSum2(i + 1, i, arr, dp);
    }

    // Exclude
    int excludeSum = maxSum2(i + 1, prev, arr, dp);

    return dp[i][prev + 1] = max(includeSum, excludeSum);
}


//Tabulation
int maxSum3(vector<int>& arr) {
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i=n-1;i>=0;i--){
        for(int prev=i-1;prev>=-1;prev--){
            // Include
            int includeSum = 0;
            if (prev == -1 || arr[i] > arr[prev]) {
                includeSum = arr[i] + dp[i+1][i+1];
            }

            // Exclude
            int excludeSum = dp[i + 1][prev+1];
            dp[i][prev + 1] = max(includeSum, excludeSum);
        }
    }
    return dp[0][0];
}

//better approach -- 1D DP
int maxSumIS(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n); // dp[i] = max sum of increasing subsequence ending at i

    // Initialize dp[i] to arr[i] — min sum ending at i is the element itself
    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
    }

    // Build the dp array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {       //dp[i] = max sum of increasing subsequence ending at i
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    // Return the maximum value from dp[] array
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> arr = {4,1, 2, 3};
    int n=arr.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    //cout << maxSum2(0,-1,arr,dp);
    //cout<<maxSumIS(arr);
    //cout<<maxSum3(arr);
    cout<<maxSum(0,arr,-1);

    return 0;
}