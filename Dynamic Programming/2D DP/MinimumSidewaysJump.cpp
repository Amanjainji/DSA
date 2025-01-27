#include<bits/stdc++.h>
using namespace std;

/*
There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

Note: There will be no obstacles on points 0 and n.

Input: obstacles = [0,1,2,3,0]
Output: 2 
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps.
Note that the frog can jump over obstacles only when making side jumps.
*/


//recursive
int solve(vector<int> &obstacles,int currlane,int pos){
    //base case
    int n=obstacles.size()-1;   //obstacles size= n+1
    if(pos==n)    //reached
        return 0;
    
    //obstacle nhi pada wa , go straight
    if(obstacles[pos+1]!=currlane){
        return solve(obstacles,currlane,pos+1);
    }
    else{ //obstacle padha wa hai,sideways jump
        int ans=INT_MAX;
        for(int i=1;i<=3;i++){
            if(i!=currlane && obstacles[pos]!=i)
                ans=min(ans,1+solve(obstacles,i,pos));
        }
        return ans;
    }
}
int minSideJumps(vector<int> &obstacles){
    return solve(obstacles,2,0);   //middle lane = 2 as there are 3 lanes 
}

//recursive + memoization
int solveMem(vector<int> &obstacles,int currlane,int pos,vector<vector<int>> &dp){
    //base case
    int n=obstacles.size()-1;   //obstacles size= n+1
    if(pos==n)    //reached
        return dp[currlane][pos]=0;
    
    if(dp[currlane][pos]!=-1)
        return dp[currlane][pos];
    
    //obstacle nhi pada wa , go straight
    if(obstacles[pos+1]!=currlane){
        return solveMem(obstacles,currlane,pos+1,dp);
    }
    else{ //obstacle padha wa hai,sideways jump
        int ans=INT_MAX;
        for(int i=1;i<=3;i++){
            if(i!=currlane && obstacles[pos]!=i){
                ans=min(ans,1+solveMem(obstacles,i,pos,dp));
            }
        }
        dp[currlane][pos]=ans;
        return dp[currlane][pos];
    }
}
int minSideJumpsMem(vector<int> &obstacles){
    vector<vector<int>> dp(4,vector<int>(obstacles.size(),-1));
    return solveMem(obstacles,2,0,dp);   //middle lane = 2 as there are 3 lanes 
}

//Tabulation
int solveTab(vector<int> &obstacles){
    vector<vector<int>> dp(4,vector<int>(obstacles.size(),1e9));
    //base case - reached at last pos
    int n=obstacles.size()-1;   //obstacles size= n+1
    dp[0][n]=0;
    dp[1][n]=0;
    dp[2][n]=0;
    dp[3][n]=0;
    for(int pos=n-1;pos>=0;pos--){
        for(int lane=1;lane<=3;lane++){
            //obstacle nhi pada wa , go straight
            if(obstacles[pos+1]!=lane){
                dp[lane][pos]=dp[lane][pos+1];
            }
            else{ //obstacle padha wa hai,sideways jump
                int ans=1e9;
                for(int i=1;i<=3;i++){
                    if(i!=lane && obstacles[pos]!=i){
                        ans=min(ans,1+dp[i][pos+1]);
                        //critical step --  pos+1
                    }
                }
                dp[lane][pos]=ans;
            }
        }
    }
    return  min(dp[2][0],min(dp[1][0]+1,dp[3][0]+1));
}

int minSideJumpsTab(vector<int> &obstacles){
    return solveTab(obstacles);   //middle lane = 2 as there are 3 lanes 
}

//Space optimization - O(1)
//only need 2 columns of size 4 , no need of a 2D array as pos just changes to pos+1
int minSideJumpsSO(vector<int> &obstacles){
    int n=obstacles.size()-1;
    vector<int> curr(4,INT_MAX);
    vector<int> next(4,INT_MAX);
    next[0]=0;
    next[1]=0;
    next[2]=0;
    next[3]=0;
    for(int pos=n-1;pos>=0;pos--){
        for(int lane=1;lane<=3;lane++){
            //obstacle nhi pada wa , go straight
            if(obstacles[pos+1]!=lane){
                curr[lane]=next[lane];
            }
            else{ //obstacle padha wa hai,sideways jump
                int ans=1e9;
                for(int i=1;i<=3;i++){
                    if(i!=lane && obstacles[pos]!=i){
                        ans=min(ans,1+next[i]);
                        //critical step --  pos+1
                    }
                }
                curr[lane]=ans;
            }
        }
        next=curr;
    }
    return  min(next[2],min(next[1]+1,next[3]+1));

}

int main(){
    vector<int> obstacles={0,1,2,3,0};
    cout<<minSideJumpsSO(obstacles);
}