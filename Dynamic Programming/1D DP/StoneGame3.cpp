#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &sv,int i){
    if(i==sv.size())
        return 0;
    
    int ans=INT_MIN;
    int total=0;
    for(int X=1;X<=3;++X){
        if(i+X-1 >=sv.size()) break;
        total+=sv[i+X-1];
        ans=max(ans,total-solve(sv,i+X));
    }
    return ans;
}
string stoneGameIII(vector<int>& stoneValue) {
    int ans=solve(stoneValue,0); //A-B

    if(ans>0) return "Alice";
    if(ans<0) return "Bob";
    return "Tie";
}

int solveTD(vector<int> &sv,int i,vector<int> &dp){
    if(i==sv.size())
        return 0;
    
    if(dp[i]!=-1)
        return dp[i];
    int ans=INT_MIN;
    int total=0;
    for(int X=1;X<=3;++X){
        if(i+X-1 >=sv.size()) break;
        total+=sv[i+X-1];
        ans=max(ans,total-solveTD(sv,i+X,dp));
    }
    return dp[i]=ans;
}
string stoneGameIII_TD(vector<int>& stoneValue) {
    vector<int> dp(stoneValue.size(),-1);
    int ans=solveTD(stoneValue,0,dp); //A-B

    if(ans>0) return "Alice";
    if(ans<0) return "Bob";
    return "Tie";
}

int solveBU(vector<int> &sv){
    vector<int> dp(sv.size()+1,0);
    for(int i=sv.size()-1;i>=0;--i){
        int ans=INT_MIN;
        int total=0;
        for(int X=1;X<=3;++X){
            if(i+X-1 >=sv.size()) break;
            total+=sv[i+X-1];
            ans=max(ans,total-dp[i+X]);
        }
        dp[i]=ans;
    } 
    return dp[0];
}
string stoneGameIII_BU(vector<int>& stoneValue) {
    int ans=solveBU(stoneValue); //A-B

    if(ans>0) return "Alice";
    if(ans<0) return "Bob";
    return "Tie";
}

//space optimization
int solveSO(vector<int>& sv) {
    int n = sv.size();
    int dp1 = 0, dp2 = 0, dp3 = 0; // Only storing last 3 states
    int ans = 0;

    for (int i = n - 1; i >= 0; --i) {
        int total = 0;
        ans = INT_MIN;
        
        for (int X = 1; X <= 3; ++X) {
            if (i + X - 1 >= n) break;
            total += sv[i + X - 1];
            int nextDp = (X == 1) ? dp1 : (X == 2 ? dp2 : dp3);
            ans = max(ans, total - nextDp);
        }

        // Shift dp values for next iteration
        dp3 = dp2;
        dp2 = dp1;
        dp1 = ans;
    }
    
    return dp1;
}

string stoneGameIII_SO(vector<int>& stoneValue) {
    int ans = solveSO(stoneValue); // A - B

    if (ans > 0) return "Alice";
    if (ans < 0) return "Bob";
    return "Tie";
}

int main(){
    vector<int> stone={1,2,3,7};
    cout<<stoneGameIII_SO(stone);
    return 0;
}
