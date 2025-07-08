#include<bits/stdc++.h>
using namespace std;

int minCostUtil(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
    if (i + 1 >= j) return 0; // No cut possible in this segment
    
    if (dp[i][j] != -1) return dp[i][j];

    int minCost = INT_MAX;
    for (int k = i + 1; k < j; k++) {
        int cost = cuts[j] - cuts[i] + 
                   minCostUtil(i, k, cuts, dp) + 
                   minCostUtil(k, j, cuts, dp);
        minCost = min(minCost, cost);
    }

    return dp[i][j] = minCost;
}

//dp[i][j] = minimum cost to cut stick between cuts[i] and cuts[j]
int minCost(int n, vector<int>& inputCuts) {
    vector<int> cuts = inputCuts;
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    int c = cuts.size();
    vector<vector<int>> dp(c, vector<int>(c, -1));
    return minCostUtil(0, c - 1, cuts, dp);
}

// Bottom-up Tabulation
int minCost2(int n, vector<int>& inputCuts) {
    vector<int> cuts = inputCuts;
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    int c = cuts.size();
    vector<vector<int>> dp(c, vector<int>(c, 0));

    // len is the length of the segment [i..j]
    for (int length = 2; length < c; length++) {        
        /*
        To compute dp[i][j], you need to ensure:
        There is at least one valid cut between cuts[i] and cuts[j].
        That happens only when j - i ≥ 2.
        */
        for (int i = 0; i < c - length; i++) {
            int j = i + length;
            dp[i][j] = INT_MAX;

            for (int k = i + 1; k < j; k++) {
                int cost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][c - 1];
}

int main(){
    int n = 7;
    vector<int> cuts = {1,3,4,5};
    cout<<minCost2(n,cuts);
}