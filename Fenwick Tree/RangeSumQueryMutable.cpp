#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> bit;
    vector<int> nums;
    int n;

    NumArray(vector<int>& arr) {
        n = arr.size();
        bit.resize(n + 1, 0);
        nums = arr;

        // build BIT
        for (int i = 0; i < n; i++) {
            updateBIT(i + 1, nums[i]);
        }
    }

    void updateBIT(int i, int elem) {
        while (i <= n) {
            bit[i] += elem;
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

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        updateBIT(index + 1, diff);
    }

    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */