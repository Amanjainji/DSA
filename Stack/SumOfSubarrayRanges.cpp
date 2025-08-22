#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findNSE(vector<int> &arr){
        stack<int> st;
        int n=arr.size();
        vector<int> nse(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            
            nse[i]=st.empty()? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSE(vector<int> &arr){
        stack<int> st;
        int n=arr.size();
        vector<int> pse(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            
            pse[i]=st.empty()? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=findNSE(arr);
        vector<int> pse=findPSE(arr);
        long long total=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            long left= i - pse[i];
            long right= nse[i] - i;
            total=total+(right*left*arr[i]);
        }
        return total;
    }
    vector<int> findNLE(vector<int> &arr){
        stack<int> st;
        int n=arr.size();
        vector<int> nle(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i])
                st.pop();
            
            nle[i]=st.empty()? n : st.top();
            st.push(i);
        }
        return nle;
    }

    vector<int> findPLE(vector<int> &arr){
        stack<int> st;
        int n=arr.size();
        vector<int> ple(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i])
                st.pop();
            
            ple[i]=st.empty()? -1 : st.top();
            st.push(i);
        }
        return ple;
    }
    long long sumSubarrayMaxi(vector<int>& arr) {
        vector<int> nle=findNLE(arr);
        vector<int> ple=findPLE(arr);
        long long total=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            long left= i - ple[i];
            long right= nle[i] - i;
            total=total+(right*left*arr[i]);
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long ans= 1LL*(sumSubarrayMaxi(nums)-sumSubarrayMins(nums));
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr={3,1,4,2};
    cout<<s.subArrayRanges(arr);
}