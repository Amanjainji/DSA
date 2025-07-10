#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Recursive function 
int minPartitions(int i, int n, string &str) {
    // Base case: If we've reached the end of the string.
    if (i == n) return 0;

    int minCost = INT_MAX;
    // Consider all possible substrings starting from the current index.
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            // If the substring is a palindrome, calculate the cost and minimize it.
            int cost = 1 + minPartitions(j + 1, n, str);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

// Main function to find the minimum number of partitions for palindrome partitioning.
int minCut(string str) {
    int n = str.size();
    return minPartitions(0, n, str) - 1;
}

// memoization
int minPartitions2(int i, int n, string &str,vector<int> &dp) {
    // Base case: If we've reached the end of the string.
    if (i == n) return 0;
    if(dp[i]!=-1)
        return dp[i];
    int minCost = INT_MAX;
    // Consider all possible substrings starting from the current index.
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            // If the substring is a palindrome, calculate the cost and minimize it.
            int cost = 1 + minPartitions2(j + 1, n, str,dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i]=minCost;
}

// Main function to find the minimum number of partitions for palindrome partitioning.
int minCut2(string str) {
    int n = str.size();
    vector<int> dp(n+1,-1);
    return minPartitions2(0, n, str,dp) - 1;
}

int minCut3(string str){
    int n = str.size();
    vector<int> dp(n+1,0); 
    // Consider all possible substrings starting from the current index.
    for(int i=n-1;i>=0;i--){
        int minCost = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, str)) {
                // If the substring is a palindrome, calculate the cost and minimize it.
                int cost = 1 + dp[j+1];
                minCost = min(minCost, cost);
            }
        }
        dp[i]=minCost; 
    }
    return dp[0]-1;
} 

int main() {
    string str = "BABABCBADCEDE";
    int partitions = minCut3(str);
    cout << "The minimum number of partitions: " << partitions << "\n";
    return 0;
}