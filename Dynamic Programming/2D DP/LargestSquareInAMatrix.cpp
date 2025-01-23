#include<bits/stdc++.h>
using namespace std;

//Recursive
int solve(vector<vector<int>> &mat,int i,int j,int &maxi){
    if(i>=mat.size() || j>= mat[0].size())
        return 0;
    
    int right=solve(mat,i,j+1,maxi);
    int diagonal=solve(mat,i+1,j+1,maxi);
    int down=solve(mat,i+1,j,maxi);

    if(mat[i][j]==1){
        int ans=1+min(right,min(diagonal,down));
        maxi=max(maxi,ans);
        return ans;
    }
    else
        return 0;
}

int maxSquare(int n,int m,vector<vector<int>> &mat){
    int maxi=0;
    solve(mat,0,0,maxi);
    return maxi;
}

//Recursive+memoization
int solve2(vector<vector<int>> &mat,int i,int j,int &maxi,vector<vector<int>> &dp){
    if(i>=mat.size() || j>= mat[0].size())
        return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int right=solve2(mat,i,j+1,maxi,dp);
    int diagonal=solve2(mat,i+1,j+1,maxi,dp);
    int down=solve2(mat,i+1,j,maxi,dp);

    if(mat[i][j]==1){
        dp[i][j]=1+min(right,min(diagonal,down));
        maxi=max(maxi,dp[i][j]);
        return dp[i][j];
    }
    else
        return dp[i][j]=0;
}

int maxSquareMem(int n,int m,vector<vector<int>> &mat){
    int maxi=0;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    solve2(mat,0,0,maxi,dp);
    return maxi;
}

//Tabulation
int maxSquareTab(int n,int m,vector<vector<int>> &mat){
    int maxi=0;
    int row=n;
    int col=m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=row-1;i>=0;i--){
        for(int j=col-1;j>=0;j--){
            int right=dp[i][j+1];
            int diagonal=dp[i+1][j+1];
            int down=dp[i+1][j];

            if(mat[i][j]==1){
                dp[i][j]=1+min(right,min(diagonal,down));
                maxi=max(maxi,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    return dp[0][0];
}

//Space optimzed --  O(n*m)  ----> O(m)
int maxSquareSO(int row,int col,vector<vector<int>> &mat){
    int maxi=0;
    vector<int> curr(col+1,0);
    vector<int> next(col+1,0);
    for(int i=row-1;i>=0;i--){
        for(int j=col-1;j>=0;j--){
            int right=curr[j+1];
            int diagonal=next[j+1];
            int down=next[j];

            if(mat[i][j]==1){
                curr[j]=1+min(right,min(diagonal,down));
                maxi=max(maxi,curr[j]);
            }
            else{
                curr[j]=0;
            }
        }
        next=curr;
    }
    return next[0];
}

//More Space optimized
int maxSquareSO2(int row, int col, vector<vector<int>> &mat) {
    int maxi = 0;
    vector<int> curr(col + 1, 0); // Store the current row computations
    int prevDiagonal = 0;        // To track the diagonal value for computation

    for (int i = row - 1; i >= 0; i--) {
        prevDiagonal = 0; // Reset diagonal for each new row
        for (int j = col - 1; j >= 0; j--) {
            int temp = curr[j]; // Store the current cell for diagonal in next iteration

            if (mat[i][j] == 1) {
                curr[j] = 1 + min({curr[j + 1], curr[j], prevDiagonal});
                maxi = max(maxi, curr[j]);
            } else {
                curr[j] = 0;
            }

            prevDiagonal = temp; // Update diagonal for the next cell
        }
    }
    return maxi;
}

int main(){
    vector<vector<int>> mat={{1,1,0},{1,1,0},{1,0,0}};
    cout<<maxSquareSO2(3,3,mat);
}