#include<bits/stdc++.h>
using namespace std;

/*
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
*/

//algorithm
/*
1) make a pair for every string of count of 0s and 1s.
2) then try include and exclude by checking condition
3) find max of include and exclude
*/

void convertStrsToNumStrs(vector<string> &strs,vector<pair<int,int>> &numStrs){
    for(auto str: strs){
        int zeros =0,ones=0;
        for(auto ch: str){
            if(ch=='0') ++zeros;
            else ++ones;
        }
        numStrs.push_back({zeros,ones});
    }
}

int solve(vector<pair<int,int>> &numStrs, int i ,int m,int n){
    if(i==numStrs.size()) return 0;

    int zeros = numStrs[i].first;
    int ones = numStrs[i].second;
    int include =0,exclude =0;
    if(m- zeros >=0 && n- ones >=0)
        include = 1+solve(numStrs,i+1,m-zeros,n-ones);
    exclude=solve(numStrs,i+1,m,n);
    return max(include,exclude);
}

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<pair<int,int>> numStrs; //np. of zeros and ones
    convertStrsToNumStrs(strs,numStrs);
    return solve(numStrs,0,m,n);
}

int solveTD(vector<pair<int,int>> &numStrs, int i ,int m,int n,vector<vector<vector<int>>> &dp){
    if(i==numStrs.size()) return 0;

    if(dp[i][m][n]!=-1)
        return dp[i][m][n];
    int zeros = numStrs[i].first;
    int ones = numStrs[i].second;
    int include =0,exclude =0;
    if(m- zeros >=0 && n- ones >=0)
        include = 1+solve(numStrs,i+1,m-zeros,n-ones);
    exclude=solve(numStrs,i+1,m,n);
    return dp[i][m][n]=max(include,exclude);
}

int findMaxFormTD(vector<string>& strs, int m, int n) {
    vector<pair<int,int>> numStrs; //np. of zeros and ones
    convertStrsToNumStrs(strs,numStrs);
    vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
    return solveTD(numStrs,0,m,n,dp);
}

int solveBU(vector<pair<int,int>> &numStrs,int m,int n){
    vector<vector<vector<int>>> dp(numStrs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
    for(int i=numStrs.size()-1;i>=0;--i){
        for(int j=0;j<=m;++j){
            for(int k=0;k<=n;++k){
                int zeros = numStrs[i].first;
                int ones = numStrs[i].second;
                int include =0,exclude =0;
                if(j- zeros >=0 && k- ones >=0)
                    include = 1+dp[i+1][j-zeros][k-ones];
                exclude=dp[i+1][j][k];
                dp[i][j][k]=max(include,exclude);
            }
        }
    }
    return dp[0][m][n];  
}

int findMaxFormBU(vector<string>& strs, int m, int n) {
    vector<pair<int,int>> numStrs; //no. of zeros and ones
    convertStrsToNumStrs(strs,numStrs);
    return solveBU(numStrs,m,n);
}

int main(){
    vector<string> strs = {"10","0001","111001","1","0"};
    int m=5,n=3;
    cout<<findMaxFormBU(strs,m,n);
}