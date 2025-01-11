#include <iostream> 
#include <vector> 
#include<bits/stdc++.h>
#include <string>

using namespace std;
int binarySearch(vector<int> arr,int target){
        int s=0;
        int e=arr.size()-1;
        int mid= s+ (e-s)/2;
        while(s<=e){
            mid= s+ (e-s)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }  
        }
        return s;
    }
int main()
{
  vector<int> nums={1,3,5,6};
  cout<<binarySearch(nums,4);
  return 0; 
}