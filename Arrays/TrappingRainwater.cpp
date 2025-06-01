#include<bits/stdc++.h>
using namespace std;

/* 1st approach ---> SC = O(2N)   TC - O(N)
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefixMax;
        vector<int> suffixMax(n,0);
        //find left max
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(height[i],maxi);
            prefixMax.push_back(maxi);
        }
        //find right max
        maxi=0;
        for(int i=n-1;i>=0;i--){
            maxi=max(height[i],maxi);
            suffixMax[i]=maxi;
        }
        //find answer by total+= min(leftMax,rightMax) - arr[i]
        int total=0;
        for(int i=0;i<n;i++){
            if(height[i]<prefixMax[i] && height[i]<suffixMax[i])
                total+=(min(prefixMax[i],suffixMax[i])-height[i]);
        }
        return total;
    }*/


//2nd approach ---> SC = O(N)
    /*
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> suffixMax(n,0);
        //find right max
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            maxi=max(height[i],maxi);
            suffixMax[i]=maxi;
        }
        //find answer by total+= min(leftMax,rightMax) - arr[i]
        int total=0;
        int leftmax=0;
        for(int i=0;i<n;i++){
            leftmax=max(height[i],leftmax);
            if(height[i]<leftmax && height[i]<suffixMax[i])
                total+=(min(leftmax,suffixMax[i])-height[i]);
        }
        return total;
    }*/


//3rd approach ---> SC = O(1)  
int trap(vector < int > & height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
        if (height[left] >= maxLeft) {
            maxLeft = height[left];
        } 
        else {
            res += maxLeft - height[left];
        }
        left++;
    }
    else {
        if (height[right] >= maxRight) {
            maxRight = height[right];
        } 
        else {
            res += maxRight - height[right];
        }
        right--;
    }
  }
  return res;
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height)<<endl;
}