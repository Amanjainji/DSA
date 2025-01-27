#include<bits/stdc++.h>
using namespace std;

/*
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

*/

//Similar pattern to 0/1 knapsack

//Recursive
int solve(vector<int> &satisfaction , int index, int time){
    //base case
    if(index==satisfaction.size())
        return 0;
    
    int include = satisfaction[index]*(time+1) + solve(satisfaction,index+1,time+1);

    int exclude= solve(satisfaction,index+1,time);

    return max(include,exclude);
}

int maxSatisfaction(vector<int> &satisfaction){
    //sort the vector
    sort(satisfaction.begin(),satisfaction.end());
    return solve(satisfaction,0,0);
}

//Recursive + memoization
int solveMem(vector<int> &satisfaction , int index, int time,vector<vector<int>> &dp){
    //base case
    if(index==satisfaction.size())
        return 0;

    if(dp[index][time]!=-1)
        return dp[index][time];

    int include = satisfaction[index]*(time+1) + solveMem(satisfaction,index+1,time+1,dp);

    int exclude= solveMem(satisfaction,index+1,time,dp);

    dp[index][time]=max(include,exclude);
    return dp[index][time];
}

int maxSatisfactionMem(vector<int> &satisfaction){
    //sort the vector
    int n=satisfaction.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    sort(satisfaction.begin(),satisfaction.end());
    return solveMem(satisfaction,0,0,dp);
}

//Tabulation
int maxSatisfactionTab(vector<int> &satisfaction){
    //sort the vector
    int n=satisfaction.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    sort(satisfaction.begin(),satisfaction.end());

    for(int index=n-1;index>=0 ;index--){
        for(int time=index;time>=0;time--){
            int include = satisfaction[index]*(time+1) + dp[index+1][time+1];
            int exclude= dp[index+1][time];

            dp[index][time]=max(include,exclude);
        }
    }
    return dp[0][0];
}

//space optimized to O(n) from O(n^2)
int maxSatisfactionSO(vector<int> &satisfaction){
    //sort the vector
    sort(satisfaction.begin(),satisfaction.end());
    int n=satisfaction.size();
    vector<int> curr(n+1,0);
    vector<int> next(n+1,0);
    for(int index=n-1;index>=0 ;index--){
        for(int time=index;time>=0;time--){
            int include = satisfaction[index]*(time+1) + next[time+1];
            int exclude=next[time];

            curr[time]=max(include,exclude);
        }
        next=curr;
    }
    return next[0];
}



int main(){
    vector<int> satisfaction={-1,-8,5,0,-9};
    cout<<maxSatisfactionSO(satisfaction);
}


