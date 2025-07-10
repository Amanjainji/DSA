// Weighted Job Scheduling 
#include <bits/stdc++.h>
using namespace std;

/*
Given a 2D array jobs[][] of order n*3, where each element jobs[i] defines start time, end time, and the profit associated with the job. The task is to find the maximum profit you can take such that there are no two jobs with overlapping time ranges.

Note: If the job ends at time X, it is allowed to choose another job that starts at time X.

Examples: 

Input: jobs[][] = [[1, 2, 50], 
                             [3, 5, 20],
                             [6, 19, 100],
                             [2, 100, 200]]
Output: 250
Explanation: The first and fourth jobs with the time range [1, 2] and [2, 100] can be chosen to give maximum profit of 50 + 200 = 250.

Input: jobs[][] = [[1, 3, 60], 
                             [2, 5, 50],
                             [4, 6, 70],
                             [5, 7, 30]]
Output: 130
Explanation: The first and third jobs with the time range [1, 3] and [4, 6] can be chosen to give maximum profit of 60 + 70 = 130.
*/


// Recusive  
int maxProfitRecur(vector<vector<int>> &jobs, 
                            int ind, int last) {
    if (ind == jobs.size())
        return 0;

    // skip the current job
    int ans = maxProfitRecur(jobs, ind+1, last);
    
    // if start of current is greater than or
    // equals to end time of previous job
    if(jobs[ind][0] >= last)
        ans = max(ans, jobs[ind][2] + 
        maxProfitRecur(jobs, ind+1, jobs[ind][1]));

    return ans;
}

int maxProfit(vector<vector<int>> &jobs) {
    int n = jobs.size();

    // Sort the jobs based on start time
    sort(jobs.begin(), jobs.end());

    return maxProfitRecur(jobs, 0, -1);
}

//memoization
int maxProfitRecur2(vector<vector<int>> &jobs, 
        int ind, int last, vector<int> &memo) {
    if (ind == jobs.size())
        return 0;

    // if the job can be taken
    if(jobs[ind][0] >= last) {

        // if the value is not calculated
        if(memo[ind] == -1) {

            // take the job
            memo[ind] = jobs[ind][2] + 
            maxProfitRecur2(jobs, ind+1, jobs[ind][1], memo);

            // leave the job and find max
            memo[ind] = max(memo[ind], 
                maxProfitRecur2(jobs, ind+1, last, memo));
        }
            
        return memo[ind];
    }
    
    // if the job can't be taken
    return maxProfitRecur2(jobs, ind+1, last, memo);
}

int maxProfit2(vector<vector<int>> &jobs) {
    int n = jobs.size();

    // Sort the jobs based on start time
    sort(jobs.begin(), jobs.end());

    // create memoization array and 
    // initialize it with -1
    vector<int> memo(n, -1);

    return maxProfitRecur2(jobs, 0, -1, memo);
}

//Tabulation
int maxProfit3(vector<vector<int>> &jobs) {
    int n = jobs.size();

    // Sort the jobs based on start time
    sort(jobs.begin(), jobs.end());

    // create a dp table
    vector<int> dp(n);

    // stores the maximum profit
    int res = 0;
    
    // iterate over all the jobs
    for(int i = n-1; i >= 0; i--) {
        dp[i] = jobs[i][2];
        
        // find the maximum profit
        for(int j = i+1; j < n; j++) {
            if(jobs[i][1] <= jobs[j][0]) {
                dp[i] = max(dp[i], dp[j] + jobs[i][2]);
            }
        }
        
        res = max(res, dp[i]);
    }

    return res;
}

//Binary Search + DP --- Most optimized 
// Function to find the closest next job.
int findNextJob(int i, vector<vector<int>> &jobs) {
    int end = jobs[i][1];
    int ans = jobs.size();
    int s = i + 1, e = jobs.size() - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (jobs[mid][0] >= end) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}

int maxProfit4(vector<vector<int>> &jobs) {
    int n = jobs.size();

    // Sort the jobs based on start time
    sort(jobs.begin(), jobs.end());

    // create a dp table
    vector<int> dp(n);
    
    // iterate over all the jobs
    for(int i = n-1; i >= 0; i--) {
        dp[i] = jobs[i][2];
        
        // find the index of next job
        int next = findNextJob(i, jobs);

        // if next job exists
        if(next < n) {
            dp[i] += dp[next];
        }
        
        // store the maximum profit
        if(i < n-1)
            dp[i] = max(dp[i], dp[i+1]);
    }

    return dp[0];
}

int main() {
    vector<vector<int>> jobs = {
        {1, 2, 50}, 
        {3, 5, 20}, 
        {6, 19, 100}, 
        {2, 100, 200}
    };
    cout << maxProfit4(jobs);
    return 0;
}