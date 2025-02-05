#include<bits/stdc++.h>
using namespace std;

static bool cmp(const string &a, const string &b){
    return (b + a) < (a + b);
}
string largestNumber(vector<int>& nums) {
    // Convert integers to strings
        vector<string> array;
        for (int num : nums) {
            array.push_back(to_string(num));
        }

        // Custom comparator for sorting
        sort(array.begin(), array.end(),cmp);

        // Handle the case where the largest number is "0"
        if (array[0] == "0") {
            return "0";
        }

        // Build the largest number from the sorted array
        string largest;
        for (const string &num : array) {
            largest += num;
        }

        return largest;
}
int main(){
    vector<int> nums={2,10,34};
    cout<<largestNumber(nums);
}