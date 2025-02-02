#include<bits/stdc++.h>
using namespace std;

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int,int> mpp;
        for(int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                mpp[i]=i+1;
            }
        }

        vector<bool> ans;
        for(auto i:queries){
                bool temp=true;
                for(auto j: mpp){
                    if(j.first>=i[0] && j.second<=i[1]){
                        temp=false;
                        break;
                    }      
                }
                ans.push_back(temp);
            }
    return ans;
}
 vector<bool> isArraySpecial2(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> parityGroup(n);
        int groupId = 0;
        parityGroup[0] = groupId;

        for (int i = 1; i < n; ++i) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                ++groupId;
            }
            parityGroup[i] = groupId;
        }

        vector<bool> result;
        for (const auto& query : queries) {
            int from = query[0];
            int to = query[1];
            result.push_back(parityGroup[from] == parityGroup[to]);
        }

        return result;
    }

int main(){
    vector<int> nums={4,3,1,6};
    vector<vector<int>> queries={{0,2},{2,3}};
    vector<bool> ans=isArraySpecial2(nums,queries);
    for(auto i:ans){
        cout<<i<<" ";
    }

}
        