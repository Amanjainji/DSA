#include <iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;
/*
void sayDigit(int n){
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

    if(n==0){
        return;
    }

    int digit=n%10;
    n=n/10;

    sayDigit(n);
    cout<<arr[digit]<<" ";

}
*/
void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
bool isSorted1(vector<int> arr,int i=0){ //my way
    int n=arr.size();
    if(i==n-1){
        return true;
    }
    if(arr[i]<=arr[i+1]){
        return isSorted1(arr,i+1);
    }
    else{
        return false;
    }
    
}
bool isSorted2(int *arr,int n){  //sliding window way
    if(n==0||n==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        return isSorted2(arr+1,n-1);
    }
    
}

int sumArray(int arr[],int n){
    if(n<=0){
        return 0;
    }
    else{
        return arr[n-1]+sumArray(arr,n-1);
    }
}

bool LinearSearch(int *arr,int n,int target){
    if(n==0){
        return false;
    }
    else{
        if(arr[0]==target){
            return true;
        }
        else{
            return LinearSearch(arr+1,n-1,target);
        }
    }
}

bool binarySearch(int arr[],int s,int e,int key){
    if(s>e){
        return false;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==key){
        return true;
    }
    else if(arr[mid]>key){
        return binarySearch(arr,s,mid-1,key);
    }
    else if(arr[mid]<key){
        return binarySearch(arr,mid+1,e,key);
    }
}

void stringReverse(string &s,int i){
    int n=s.length();
    if(i>n-i-1){
        return;
    }

    swap(s[i],s[n-i-1]);
    i++;
    stringReverse(s,i);
}

bool pallindromeString(string &s,int i){
    int n=s.length();
    if(i>n-i-1){
        return true;
    }

    if(s[i]!=s[n-i-1]){
        return false;
    }
    else{
        return pallindromeString(s,i+1);
    }
}

int power(int x,int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return x;
    }

    int ans=pow(x,n/2);
    if(n%2==0){
        return ans*ans;
    }
    else{
        return x*ans*ans;
    }
}

void bubbleSortRecursion(int *arr,int n){
    if(n==0 || n==1){
        return;
    }
    else{
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);

            }
        }
        bubbleSortRecursion(arr,n-1); 
    }
}

void insertionSortRecursive(int arr[], int n) {
    // Base case
    if (n <= 1)
        return;

    // Sort first n-1 elements
    insertionSortRecursive(arr, n - 1);

    // Insert last element at its correct position in sorted array.
    int last = arr[n - 1];
    int j = n - 2;

    /* Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position */
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

void SelectionSortRecursive(int arr[], int n) {
    // Base case
    if (n <= 1)
        return;
    // Find the minimum element in the unsorted part of the array
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[minIndex]>arr[j]){
            minIndex=j;
      }
    }
    // Swap the minimum element with the first element of the unsorted part
    if (minIndex!=i){
      int temp=arr[minIndex];
      arr[minIndex]=arr[i];
      arr[i]=temp;
    }
    }
    //recursion for the remaining part of unsorted array
    SelectionSortRecursive(arr+1, n - 1);
}

void merge(int *arr,int s,int e){
    int mid=(s+e)/2;

    int len1 = mid-s+1;
    int len2= e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex =s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainArrayIndex++];
    }
    mainArrayIndex =mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays
    int index1=0;
    int index2=0;
    mainArrayIndex=s;

    while(index1< len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainArrayIndex++]=first[index1++];
        }
        else{
            arr[mainArrayIndex++]=second[index2++];
        }
    }

    while(index1 < len1){
        arr[mainArrayIndex++]=first[index1++];
    }
    while(index2<len2){
        arr[mainArrayIndex++]=second[index2++];
    }
}

void mergeSort(int *arr,int s,int e){
    //base case
    if(s>=e){
        return;
    }

    int mid=(s+e)/2;

    //left part sort krna hai
    mergeSort(arr,s,mid);

    //right part sort krna hai
    mergeSort(arr,mid+1,e);

    //merge
    merge(arr,s,e);
}
int partition(int arr[],int s,int e){
    int pivot =arr[s];

    int cnt=0; //kitne element chote hai starting element se

    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }

    int pivotIndex= s+cnt;
    swap(arr[pivotIndex],arr[s]);

    //left and right wala part set krna , left mein sab chote pivot se and right mein sb bade 

    int i=s,j=e;

    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]< pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotIndex;
}
void quickSort(int arr[],int s,int e){
    //base case 
    if(s>=e){
        return;
    }
    //partition karenge
    int p=partition(arr,s,e); //pivot

    //left part sort krenge
    quickSort(arr,s,p-1);

    //right part sort krenge
    quickSort(arr,p+1,e);
}

void solve(vector<int> nums,vector<int> output,int index , vector<vector<int>> &ans){
    //base case
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }
    //exclusion
    solve(nums,output,index+1,ans);

    //inclusion
    int element = nums[index];
    output.push_back(element);
    solve(nums,output,index+1,ans);
}
vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(nums,output,index,ans);
    return ans; 
}


void solves(string digits,string output,int index,vector<string> &ans,vector<string> mapping){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }

        int number=digits[index]-'0';
        string value=mapping[number];

        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solves(digits,output,index+1,ans,mapping);
            output.pop_back();
        }
    }

vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string output="";
        int index=0;
        vector<string> mapping ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solves(digits,output,index,ans,mapping);
    return ans;
}
int matrixSum(vector<vector<int>>& nums) {
  int row=nums.size();
  int col=nums[0].size();

  int sum=0;
  int i=0;
  while(i<col){
    int max=0;
    for(int j=0;j<row;j++){
      if(max<nums[j][i]){
        max=nums[j][i];
      }
    }
    sum+=max;
    i++;
  }
  return sum;
}

void binarySearch1(vector<int>& nums,int s,int e,int target,int &ans){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                break;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
    }
int search(vector<int>& nums, int target) {
        int ans=-1;
        if(nums.size()==0){
            return -1;
        }
        if(nums.size()==1){
            if(nums[0]==target){
                return 0;
            }
            return ans;
        }
        int e=nums.size()-1;
        int pivot;
        for(int i=0;i<e;i++){
            if(nums[i]>nums[i+1]){
                pivot=i;
                break;
            }
        }
        binarySearch1(nums,0,pivot,target,ans);
        binarySearch1(nums,pivot+1,e,target,ans);
        return ans;
    }

int removeDuplicates1(vector<int>& nums) {
        vector<int> temp (nums.size(),-1);
        int n=nums[0];
        int k=0;
        temp[k]=(n);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=n){
                n=nums[i];
                temp[++k]=n;
            }
        }
        nums=temp;
        return k+1;
}

int binarySearchInsert(vector<int> arr,int target){
        int s=0;
        int ans=-1;
        int e=arr.size()-1;
        int mid= s+ (e-s)/2;
        while(s<=e){
            if(arr[mid]==target){
                ans=mid;
            }
            else if(arr[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid= s+ (e-s)/2;
        }
        if(ans==-1){
            return mid;
        }
        else{
            return ans;
        }
    }
int main(){
    vector<int> arr={1,2,2,4,5,6,7};
    int arr2[8]={1,2,3,7,9,8,5,6};
    //cout<<isSorted2(arr2,5)<<" ";
    //cout<<sumArray(arr2,6);
    //sayDigit(512);
    //cout<<binarySearch(arr2,0,5,2);
    string ko="naman";
    //stringReverse(k,0);
    //cout<<pallindromeString(k,0);
    //cout<<power(2,10);
    //bubbleSortRecursion(arr2,8);
    vector<string> str={"a"};
    //cout<< longestCommonPrefix(str);
    //SelectionSortRecursive(arr2,8);
    //mergeSort(arr2,0,7);
    /*
    for(int i=0;i<8;i++){
        cout<<arr2[i]<<" ";
    }*/
    vector<int> nums={1,2,3};
    //vector<vector<int>> m=subsets(nums);
    /*for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }*/
    vector<int> candidates = {10,1,2,7,6,1,5};
    //quickSort(arr2,0,7);
    //vector<vector<int>> kr={{7,2,1},{6,4,2},{6,5,3},{3,2,1}};
    //cout<<matrixSum(kr);
    vector<int> arr9={4,5,6,7,0,1,2};
    vector<int> arr90={1};
    //cout<<search(arr90,0);
    vector<int> arr10={1,2,2,4,4,4,4};
    //cout<<removeDuplicates1(arr10)<<endl;
    /*
    for(int i=0;i<7;i++){
        cout<<arr10[i]<<" ";
    }*/
    vector<int> nums1={1,3,5,6};
    cout<<binarySearchInsert(nums1,3);

    return 0;
}