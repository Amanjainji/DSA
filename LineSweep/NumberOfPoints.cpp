#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfPoints(vector<vector<int>>& nums) {
            vector<int> diff(102, 0);

            // Step 1: mark events
            for (auto &it : nums) {
                diff[it[0]] += 1;
                diff[it[1] + 1] -= 1;
            }

            // Step 2: sweep
            int curr = 0, ans = 0;

            for (int i = 1; i <= 100; i++) {
                curr += diff[i];
                if (curr > 0) ans++;
            }

            return ans;
        }
};

int main(){
    vector<vector<int>> nums={{1,3},{5,8}};
    Solution s;
    cout<<s.numberOfPoints(nums)<<endl;
    return 0;
}