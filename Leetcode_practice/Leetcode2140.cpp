#include<bits/stdc++.h>
using namespace std;

    //recursive
    /*
        long long solve(int i,vector<vector<int>>& questions){
            if(i>=questions.size())
                return 0;
            
            //incl
            long long incl=questions[i][0]+solve(i+questions[i][1]+1,questions);
            //excl
            long long excl=solve(i+1,questions);
    
            return max(incl,excl);
        }
        long long mostPoints(vector<vector<int>>& questions) {
            return solve(0,questions);
        }
    */
    //memoization
    /*
        long long solve2(int i,vector<vector<int>>& questions,vector<long long> &dp){
            if(i>=questions.size())
                return 0;
            
            if(dp[i]!=-1)
                return dp[i];
            //incl
            long long incl=questions[i][0]+solve2(i+questions[i][1]+1,questions,dp);
            //excl
            long long excl=solve2(i+1,questions,dp);
    
            return dp[i]=max(incl,excl);
        }
        long long mostPoints(vector<vector<int>>& questions) {
            vector<long long> dp(questions.size()+1,-1);
            return solve2(0,questions,dp);
        }
    */
    //tabulation
        long long mostPoints(vector<vector<int>>& questions) {
            int n=questions.size();
            vector<long long> dp(questions.size()+1,0);
            for(int i=n-1;i>=0;i--){
                //incl
                long long incl=0;
                if(i+questions[i][1]+1<=n)
                    incl=questions[i][0]+dp[i+questions[i][1]+1];
                else
                    incl=questions[i][0];
                //excl
                long long excl=dp[i+1];
    
                dp[i]=max(incl,excl);
            }
            return dp[0];
        }

int main(){
    /*
    Input: questions = [[3,2],[4,3],[4,4],[2,5]]
    Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
    */
    vector<vector<int>> questions={{3,2},{4,3},{4,4},{2,5}};
    cout<<mostPoints(questions);

}
