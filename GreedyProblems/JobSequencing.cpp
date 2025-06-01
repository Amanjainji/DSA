#include<bits/stdc++.h>
using namespace std;

/*
You are given three arrays: id, deadline, and profit, where each job is associated with an ID, a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:
The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
Examples :

Input: id = [1, 2, 3, 4], deadline = [4, 1, 1, 1], profit = [20, 1, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
*/
/*
static bool cmp(vector<int> a,vector<int> b){
    return a[0]>b[0];
}
vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,vector<int> &profit) {
    vector<vector<int>> v;
    int lastDur=-1; 
    for(int i=0;i<id.size();i++){
        vector<int> temp(3); //{profit,id,deadline}
        temp[0]=profit[i];  
        temp[1]=id[i];
        temp[2]=deadline[i];
        v.push_back(temp);
        if(deadline[i]>lastDur)
            lastDur=deadline[i];
    }
    sort(v.begin(),v.end(),cmp);

    vector<int> schedule(lastDur+1,-1);
    int count=0;
    int maxProfit=0;
    for(int i=0;i<v.size();i++){
            int currProfit=v[i][0];
            int currJobId=v[i][1];
            int currDead=v[i][2];

            for(int k=currDead;k>0;k--){
                if(schedule[k]==-1){
                    maxProfit+=currProfit;
                    schedule[k]=currJobId;
                    count++;
                    break;
                }
            }

        }
    return {count,maxProfit};
}

int main(){
    
    vector<int> id = {1, 2, 3, 4}, deadline = {4, 1, 1, 1}, profit = {20, 10, 40, 30};
    vector<int> k=JobSequencing(id,deadline,profit);
    for(auto i: k){
        cout<< i <<" ";
    }

    vector<int> id ={1,2,3,4,5}, deadline ={2,1,2,1 ,1},profit={100 ,19 ,27 ,25 ,15};
    vector<int> k=JobSequencing(id,deadline,profit);
    for(auto i: k){
        cout<< i <<" ";
    }
}*/

#include<bits/stdc++.h>

using namespace std;
// A structure to represent a job 
struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
   //Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(Job arr[], int n) {

      sort(arr, arr + n, comparison);
      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, arr[i].dead);
      }

      int slot[maxi + 1];

      for (int i = 0; i <= maxi; i++)
         slot[i] = -1;

      int countJobs = 0, jobProfit = 0;

      for (int i = 0; i < n; i++) {
         for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
               break;
            }
         }
      }

      return make_pair(countJobs, jobProfit);
   }
};
int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
} 