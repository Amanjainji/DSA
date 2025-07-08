#include <bits/stdc++.h>
using namespace std;

/*
Rod Cutting Problem:
Given a rod of length 'N' and an array 'price' where price[i] represents the price of a rod piece of length (i+1),
find the maximum value obtainable by cutting up the rod and selling the pieces.
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive function with memoization
int solve(int i, int rodLen, vector<int>& price, vector<vector<int>>& dp) {
    if (i == 0) {
        // Only length-1 pieces can be used
        return rodLen * price[0];
    }

    if (dp[i][rodLen] != -1)
        return dp[i][rodLen];

    int notTake = solve(i - 1, rodLen, price, dp); // Skip this length
    int take = INT_MIN;

    int currentLength = i + 1;
    if (currentLength <= rodLen) {
        take = price[i] + solve(i, rodLen - currentLength, price, dp); // Take this length
    }

    return dp[i][rodLen] = max(take, notTake);
}

int cutRod(vector<int>& price, int rodLen) {
    int L = price.size(); // Number of available lengths
    vector<vector<int>> dp(L, vector<int>(rodLen + 1, -1));
    return solve(L - 1, rodLen, price, dp);
}

int cutRod2(vector<int>& price, int rodLen) {
    int L = price.size();  // Number of available lengths (1 to L)
    vector<vector<int>> dp(L, vector<int>(rodLen + 1, 0));

    // Base case: only using piece of length 1 (i = 0)
    for (int len = 0; len <= rodLen; len++) {
        dp[0][len] = len * price[0];  // Only use 1-length pieces
    }

    for (int i = 1; i < L; i++) {
        int currLength = i + 1;
        for (int len = 0; len <= rodLen; len++) {
            int notTake = dp[i - 1][len]; // skip current length
            int take = INT_MIN;
            if (currLength <= len)
                take = price[i] + dp[i][len - currLength]; // take current length (unbounded)

            dp[i][len] = max(take, notTake);
        }
    }

    return dp[L - 1][rodLen];
}

int cutRodSO(vector<int>& price, int rodLen) {
    int L = price.size(); // Number of available cut sizes (1 to L)

    vector<int> dp(rodLen + 1, 0);

    // Base case: only using piece of length 1 (price[0])
    for (int len = 0; len <= rodLen; len++) {
        dp[len] = len * price[0];
    }

    // Consider each piece length from 2 to L
    for (int i = 1; i < L; i++) {
        int currLength = i + 1;
        for (int len = 0; len <= rodLen; len++) {
            int notTake = dp[len];
            int take = INT_MIN;
            if (currLength <= len) {
                take = price[i] + dp[len - currLength];
            }
            dp[len] = max(notTake, take);
        }
    }

    return dp[rodLen];
}

int main() {
    vector<int> price = {2, 5, 7, 8, 10}; // price[i] = price of rod piece of length i+1
    int N = 7; // Rod length

    cout << "The maximum obtainable value is " << cutRodSO(price, N) << endl;

    return 0;
}
