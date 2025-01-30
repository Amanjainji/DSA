#include<bits/stdc++.h>
using namespace std;
/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
*/
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    for (int num : numSet) {
        // Check if num is the start of a sequence (num - 1 should not exist)
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int count = 1;

            // Expand the sequence
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                count++;
            }

            longest = max(longest, count);
        }
    }
    return longest;
}
int main(){
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout<<longestConsecutive(nums);
}