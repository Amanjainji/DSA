#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

vector<int> merge(vector<int> &nums1, vector<int> &nums2){
       
        int total=nums1.size()+nums2.size();
        vector<int> ans;
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j<n){
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> k= merge(nums1,nums2);
        int n=k.size();
        if(n/2==0){
            double ans=(double)k[n/2];
            return ans; 
        }
        if(n%2!=0){
            double ans=(double)k[n/2];
            return ans;    
        }
        else{
            double ans= (double)(k[n/2]+k[n/2-1])/2;
            return ans;    
        }
}

int main(){
    vector<int> arr1={1,2,3,4,5};
    vector<int> arr2={6,7,8,9,10,11,12,13,14,15,16,17};
    cout<<findMedianSortedArrays(arr1,arr2);
}