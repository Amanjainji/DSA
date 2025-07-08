#include <bits/stdc++.h>
using namespace std;

/*
You are given k identical eggs and you have access to a n-floored building from 1 to k.

There exists a floor f where 0 <= f <= n such that any egg dropped from a floor higher than f will break, and any egg dropped from or below floor f will not break. There are a few rules given below:

    An egg that survives a fall can be used again.
    A broken egg must be discarded.
    The effect of a fall is the same for all eggs.
    If the egg doesn't break at a certain floor, it will not break at any floor below.
    If the egg breaks on a certain floor, it will break on any floor above.

Your task is to find the minimum number of moves you need to determine the value of f with certainty.
*/

/*
Input: k = 2, n = 36
Output: 8
Explanation: In all the situations, 8 maximum moves are required to find the maximum floor. Following is the strategy to do so:

8+7+6+5+4+3+2+1 = 36

Drop from floor 8 → If breaks, check 1-7 sequentially.
Drop from floor 15 → If breaks, check 9-14.
Drop from floor 21  → If breaks, check 16-20.
Drop from floor 26 → If breaks, check 22-25.
Drop from floor 30 → If breaks, check 27-29.
Drop from floor 33 → If breaks, check 31-32.
Drop from floor 35 → If breaks, check 34.
Drop from floor 36 → Final check.
*/

//recursive
int eggDrop(int eggs, int n) {
    // if there is less than or equal to one floor
    if (n == 1 || n == 0)
        return n;

    // if there is only one egg
    if (eggs == 1)
        return n;

    // to store the minimum number of attempts
    int res = INT_MAX;

    // Consider all droppings from
    // 1st floor to nth floor
    for (int i = 1; i <= n; i++) {
        int cur = 1 + max(eggDrop(eggs - 1, i - 1), eggDrop(eggs, n - i));
        res = min(res, cur);
    }

    return res;
}

//Better Approach -- TC = O(n*k*log(n))  using binary search
int solve2(int eggs, int n, vector<vector<int>>& dp) {
    // Base cases
    if (n == 0 || n == 1) return n;
    if (eggs == 1) return n;
    if (dp[eggs][n] != -1) return dp[eggs][n];

    int low = 1, high = n, res = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        int breakEgg = solve2(eggs - 1, mid - 1, dp);    // Egg breaks
        int notBreak = solve2(eggs, n - mid, dp);        // Egg doesn't break

        int worst = 1 + max(breakEgg, notBreak);    // Worst case

        res = min(res, worst);

        if (breakEgg < notBreak) {
            // Go higher
            low = mid + 1;
        } else {
            // Go lower
            high = mid - 1;
        }
    }

    return dp[eggs][n] = res;
}

int EggDrop2(int k, int n) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    return solve2(k, n, dp);
}

//most optimized  -- TC - O(n*k) 
int EggDrop3(int k, int n) {
    // dp[k][m] = max floors we can check with k eggs and m moves
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    int m = 0;
    while (dp[k][m] < n) {
        m++;
        for (int i = 1; i <= k; i++) {
            dp[i][m] = dp[i - 1][m - 1] + dp[i][m - 1] + 1;
        }
    }
    return m;
}

// Function to find minimum number of attempts 
// needed in order to find the critical floor
int eggDrop4(int k, int n) {

    // create an array to store the results
    vector<int> dp(k + 1, 0);

    // to count the number of moves
    int cnt = 0;

    // while the number of floors is less than k
    while (dp[k] < n) {
        cnt++;

        // for each egg
        for (int i = k; i > 0; i--) {
            dp[i] += 1 + dp[i - 1];
        }
    }
    return cnt;
}

int main() {
    int k = 2; // number of eggs
    int n = 36; // number of floors
    cout << "Minimum number of attempts in worst case: " << eggDrop4(k, n) << endl;
    return 0;
}
