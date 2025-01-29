#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int> &a,int curr,int prev){
    //base case
    if(curr==n)
        return 0;

    //include
    int take=0;
    if(prev==-1 || a[curr]>a[prev]){
        take=1+solve(n,a,curr+1,curr);
    }

    //exclude
    int notTake = 0 + solve(n,a,curr+1,prev);
    return max(take,notTake);
}

int longestSubsequence(int n,vector<int> &a){
    return solve(n,a,0,-1);
}

int solveMem(int n,vector<int> &a,int curr,int prev,vector<vector<int>> &dp){
    //base case
    if(curr==n)
        return 0;

    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }

    //include
    int take=0;
    if(prev==-1 || a[curr]>a[prev]){
        take=1+solveMem(n,a,curr+1,curr,dp);
    }

    //exclude
    int notTake = 0 + solveMem(n,a,curr+1,prev,dp);
    dp[curr][prev+1]= max(take,notTake);
    return dp[curr][prev+1];
}

int longestSubsequenceMem(int n,vector<int> &a){
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solveMem(n,a,0,-1,dp);
}
//TC -O(N^2)     SC-O(N^2)
int longestSubsequenceTab(int n,vector<int> &a){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
            //include
            int take=0;
            if(prev==-1 || a[curr]>a[prev]){
                take=1+dp[curr+1][curr+1];   
            }

            //exclude
            int notTake = 0 + dp[curr+1][prev+1];  //prev+1 because prev can be -1
            dp[curr][prev+1]= max(take,notTake);
        }
    }
    return dp[0][0];
}

//space optimization TC -O(N^2)  SC-O(N)
int longestSubsequenceSO(int n,vector<int> &a){
    vector<int> currRow(n+1,0);
    vector<int> nextRow(n+1,0);
    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
            //include
            int take=0;
            if(prev==-1 || a[curr]>a[prev]){
                take=1+nextRow[curr+1];   
            }

            //exclude
            int notTake = 0 + nextRow[prev+1];  //prev+1 because prev can be -1
            currRow[prev+1]= max(take,notTake);    
        }
        nextRow=currRow;
    }
    return nextRow[0];
}
//more optimization TC -O(N*log N)    SC-O(N)
int longestSubsequenceNew(int n,vector<int> &a){
    if(n==0)
        return 0;
    
    vector<int> ans;
    ans.push_back(a[0]);

    for(int i=1;i<n;i++){
        if(a[i]> ans.back())
            ans.push_back(a[i]);
        else{
            //find index of just bada element in ans
            int index=lower_bound(ans.begin(),ans.end(),a[i]) -ans.begin();
            ans[index]=a[i];
        }
    }
    return ans.size();
}

int main(){
    vector<int> arr={5,8,3,7,9,1};
    cout<<longestSubsequenceNew(6,arr);
}