#include<bits/stdc++.h>
using namespace std;

//Recursive
int numberOfWays(int n,int k){
    if(n<=0)  //Invalid case
        return 0;
    //base case 
    if(n==1)
        return k;
    if(n==2)
        return k+(k*(k-1));

    int ans=numberOfWays(n-2,k)*(k-1) + numberOfWays(n-1,k)*(k-1);

    return ans;
}

//Recursive + Memoization
int solve(int n,int k,vector<int> &dp){
    if(n<=0)  //Invalid case
        return 0;
    //base case 
    if(n==1)
        return k;
    if(n==2)
        return k+(k*(k-1));

    //memoization
    if(dp[n]!=-1)
        return dp[n];
    
    dp[n]=solve(n-2,k,dp)*(k-1) + solve(n-1,k,dp)*(k-1);
    return dp[n];
}
int numberOfWays2(int n,int k){
    vector<int> dp(n+1,-1);
    return solve(n,k,dp);
}

//Tabulation
int solveTab(int n,int k){
    vector<int> dp(n+1,-1);
    if(n<=0)  //Invalid case
        return 0;
    //base case analysis
    dp[1]=k;
    dp[2]=k+(k*(k-1));

    for(int i=3;i<=n;i++){    
        dp[i]=dp[i-2]*(k-1) + dp[i-1]*(k-1);
    }
    return dp[n];
}

int numberOfWays3(int n,int k){
    return solveTab(n,k);
}

//Space optimization
int numberOfWays4(int n,int k){
    if(n<=0)  //Invalid case
        return 0;

    //base case analysis
    int prev2=k;
    int prev1=k+(k*(k-1));

    for(int i=3;i<=n;i++){    
        int ans=prev2*(k-1) + prev1*(k-1);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}

int main(){
    cout<<numberOfWays4(4,3);
}