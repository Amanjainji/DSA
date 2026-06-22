#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bit;
    int n;

    void update(int i) {
        while (i <= n) {
            bit[i] += 1;
            i += (i & -i);
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }

    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        vector<int> result(n);

        // Step 1: Coordinate Compression
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;
        int r = 1;
        for (int s : sorted) {
            if (rank.find(s) == rank.end()) {
                rank[s] = r++;
            }
        }

        // BIT initialization
        bit.resize(n + 1, 0);

        // Step 2: Traverse right to left
        for (int i = n - 1; i >= 0; i--) {
            int rnk = rank[nums[i]];
            result[i] = query(rnk - 1);
            update(rnk);
        }

        return result;
    }
};

int main(){
    vector<int> v={5,2,6,1};
    Solution s;
    vector <int> ans=s.countSmaller(v);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

}