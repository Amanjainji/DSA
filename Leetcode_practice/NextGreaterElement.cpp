#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int> &nums1){
    vector<int> nums2=nums1;
    unordered_map<int,int> mpp;
    stack<int> st;

    for(int i = nums2.size()-1 ; i>=0; i--){     
    // check if the stack holds any values and compare them with array values.   
        while(!st.empty() && st.top() <= nums2[i]){// if the values in the stack are less than the array values delete them.
            st.pop();
        }
        // if stack is not empty set the value to the top.
        if(!st.empty()) 
            mpp[i] = st.top();
        else
            mpp[i] = 0;
        
        st.push(nums2[i]);
      }
      vector<int> ans(nums2.size(),0);
    //check for array-1 values in map and store them.
      for(int i=0;i<nums2.size();i++){
        ans[i]=mpp[i];
      }
      return ans;

}

int main(){
    vector<int> nums={1,7,5,1,9,2,5,1};
    vector<int> k=nextLargerElement(nums);
    for(auto i:k){
        cout<<i<<" ";
    }
}