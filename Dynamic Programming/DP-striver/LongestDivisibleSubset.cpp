#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the largest divisble subset
    vector<int> largestDivisibleSubset(vector<int> nums) {
        int n = nums.size(); // Size of the array 

        sort(nums.begin(), nums.end());

        vector<int> ans; // To store the LDS
        vector<int> dp(n, 1); // DP array 
        vector<int> parent(n); // Array to keep record of the parent

        // To store the index of last element in the LDS
        int lastIndex = 0; 

        // To store the length of LDS
        int maxLen = 0;

        // Computing the DP array 
        for(int i = 0; i < n; i++) {
            parent[i] = i; // Assign the parent to itself

            // For each previous index
            for(int prevInd = 0; prevInd < i; prevInd++) {
                
                // If the element at index i can be included in the LDS ending at index j
                if(nums[i] % nums[prevInd] == 0 && dp[i] < dp[prevInd] + 1) {

                    dp[i] = dp[prevInd] + 1; // Update the DP value
                    parent[i] = prevInd; // Store the parent
                }
            }

            // If a longer LDS is found, update the values
            if(dp[i] > maxLen) {
                lastIndex = i;
                maxLen = dp[i];
            }
        }

        // Backtracking
        int i = lastIndex;

        // Until we reach an index which is its own parent
        while(parent[i] != i) {
            ans.push_back(nums[i]); // Add the element at current index
            i = parent[i]; 
        }
        ans.push_back(nums[i]); // Adding the last element 

        // Return the computed result
        return ans;
    }  
};


int main() {
    vector<int> nums = {3, 5, 10, 20};
    
    // Creating an object of Solution class
    Solution sol;
    vector<int> ans = sol.largestDivisibleSubset(nums);
    
    cout << "The largest divisible subset is: ";
    for(int x : ans) cout << x << " ";
    
    return 0;
}