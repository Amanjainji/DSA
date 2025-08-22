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
    int sumSubarrayMins(vector<int>& arr) {
        long long mod=1000000007;
        vector<int> nse=findNSE(arr);
        vector<int> pse=findPSE(arr);
        long long total=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            long left= i - pse[i];
            long right= nse[i] - i;
            total=(total+(right*left*arr[i])%mod)%mod;
        }
        return (int)total;
    }
};

int main(){
    Solution s;
    vector<int> arr={3,1,4,2};
    cout<<s.sumSubarrayMins(arr);
}