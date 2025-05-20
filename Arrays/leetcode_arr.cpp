#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void Bubble(int arr[],int n){
  for(int i=0;i<n-1;i++){
    int flag=0;
    for(int j=0;j<n-1-i;j++){
      if(arr[j]>arr[j+1]){
        int temp;
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        flag=1;
      }
    }
    if(flag==0){
      break;
    }
  }
}

/*
problem: hamming weight
    int hammingWeight(uint32_t n){
    int count= 0;
    while(n!=0){
        //checking last bit
        if(n&1){
            count++;
        }
        n=n>>1;
    }
    return count;
}
*/

/*
//problem 1: Alternate Swap

void AlternateSwap(int arr[],int size){ 
    for(int i=0;i<size;i=i+2){
        if((i+1)<size){
            swap(arr[i],arr[i+1]);
        }
    }
}

*/

/*
//problem 2 find Unique Element
int findUniqueElement(int *arr,int size){
    int ans=0;
    for (int i=0;i<size;i++){  //XOR PROPERTY a^a=0 , 0^a=a
        ans = ans^arr[i]; //remaining element will be unique
    }
    return ans;
}
*/




/*
//problem 3: unique number of occurences

void Bubble(int arr[],int n){
  for(int i=0;i<n-1;i++){
    int flag=0;
    for(int j=0;j<n-1-i;j++){
      if(arr[j]>arr[j+1]){
        int temp;
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        flag=1;
      }
    }
    if(flag==0){
      break;
    }
  }
}

bool UniqueNumberOfOccurences(int arr[],int size){
    int arr1[size];
    for(int i=0;i<size;i++){  //making a copy
        arr1[i]=arr[i];
    }
    Bubble(arr1,size); //sort
    int *CountsArr=new int[size]; //array of counts
    int i=0;
    int n=0;
    while(i<=size){
        int count=1;
        for(int j=i+1;j<size;j++){
            if(arr1[i]==arr1[j]){
                count++;
            }
            else{
                break;  //as array is sorted
            }
        }
        CountsArr[n]=count; 
        i=i+count;
        n++;
        }
        int CountsArrSize=n-1;
        Bubble(CountsArr,CountsArrSize);
        for(int k=0;k<CountsArrSize-1;k++){
            if(CountsArr[k]==CountsArr[k+1]){
                return false;
        }
    }
return true;
    
}
*/

//problem 4: finding single duplicate element of an array[N] =[1,2,3...N-1]
/*
//1st approach
void Bubble(int arr[],int n){
  for(int i=0;i<n-1;i++){
    int flag=0;
    for(int j=0;j<n-1-i;j++){
      if(arr[j]>arr[j+1]){
        int temp;
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        flag=1;
      }
    }
    if(flag==0){
      break;
    }
  }
}
int findDuplicate(int arr[],int size){
    Bubble(arr,size);
    for(int i=0;i<size-1;i++){
        if(arr[i]==arr[i+1]){
            return arr[i];
        }
    }
}
//2nd approach - XOR method

int findDuplicate2(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];
    }

     for(int i=1;i<size;i++){
        ans=ans^i;
     }
    return ans;
}
*/

//problem 5
/*finding all duplicates in an array and return all the integers that occurs twice only */
/*
void findDuplicatesTwice(int arr[], int size) {
    int Dup[size]={0};
    for (int i = 0; i < size ; i++) {
            Dup[arr[i]]++;
        }
    
    int Dupp[100];
    int n=0;
    for (int i = 0; i < size ; i++) {
            if(Dup[i]==2){
                Dupp[n]=i;
                n++;
            }
        }
    printarr(Dupp,n);
}


//way 2
vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int n=abs(nums[i]);
            int index=n-1;
            if(nums[index]<0){
                ans.push_back(n);
            }
            nums[index]=nums[index]*-1;
        }
        return ans;

    }
*/

//problem 6:
/* find Array Intersection for sorted arrays

vector<int> findArrayIntersection(int arr1[], int n ,int arr2[],int m ){
  vector<int> ans;
  int i=0,j=0;
  while(i<n && j<m){
    if(arr1[i]==arr2[j]){
      ans.push_back(arr1[i]);
      i++;
      j++;
    }
    else if(arr1[i]<arr2[j]){
      i++;
    }
    else{
      j++;
    }
  }
  return ans;
}*/
//problem 7: find pair sum 
/*
vector<vector<int>> pairSum(vector<int> arr,int s ){ // returning type:array of arrays
  vector<vector<int>> ans;

  for(int i=0;i<arr.size();i++){
    for(int j=i+1;j<arr.size();j++){
      if(arr[i]+arr[j]==s){
        vector<int> temp;
        temp.push_back(min(arr[i],arr[j]));
        temp.push_back(max(arr[i],arr[j]));
        ans.push_back(temp);
      }
    }
  }
  return ans;
}
*/

//problem 8
/* //find Triplet Sum

vector<vector<int>> findTripletSum(vector<int> arr,int s){
  sort(arr.begin(),arr.end());
  vector<vector<int>> ans;
  for(int i=0;i<arr.size();i++){
    for(int j=i+1;j<arr.size();j++){
      for(int k=j+1;k<arr.size();k++){
        if(arr[i]+arr[j]+arr[k]==s){
          vector<int> temp;
          temp.push_back(arr[i]);
          temp.push_back(arr[j]);
          temp.push_back(arr[k]);
          sort(temp.begin(),temp.end());
          ans.push_back(temp);
        }
      }
    }
  }
  return ans;
}

*/
/*
void sort01(vector<int> &arr){
//you can complete this in single line by vector sort but time complexity is O(n logn). now for time complexity O(n). 
  int i=0,j=arr.size()-1;
  while(i<=j){
    if(arr[i]==0){
      i++;
    }
    if(arr[j]==1){
      j--;
    }
    if(arr[i]==1&arr[j]==0){
      swap(arr[i],arr[j]);
      i++;
      j--;
    }
  }
}
*/

//you can complete this in single line by vector sort but time complexity is O(n logn). now for time complexity O(n).
/*
void sort012(int arr[], int size){
  int low = 0; // Pointer for 0s
  int mid = 0; // Pointer for 1s
  int high = size - 1; // Pointer for 2s

  while (mid <= high) {
    if (arr[mid] == 0) {
      swap(arr[low], arr[mid]);
      low++;
      mid++;
    } else if (arr[mid] == 1) {
      mid++;
    } else {
      swap(arr[mid], arr[high]);
      high--;
    }
  }
}
*/



int main(){
  int arr[8]={2,3,4,9,8,7,5,6};
    int arr1[3]={2,3};
    int arr2[6]={1,2,3,4,5,6}; 
    int arr3[9]={1,2,3,3,3,3,4,5,6}; 
    int arr4[5]={7,9,1,2,3};
    int num=25;
    //AlternateSwap(arr,8);
    //printarr(arr,8);
    // cout<<findUniqueElement(arr1,7);
    //cout<<UniqueNumberOfOccurences(arr1 ,6);
    //cout<<findDuplicate2(arr2,7);
    //cout<<hammingWeight(num);
    //findDuplicatesTwice(arr1,7);
    
    /*vector<int> arra =findArrayIntersection(arr1,3,arr2,6);
    for(int i=0;i<arra.size();i++){
      cout<<arra[i]<<" "; 
    }
    */
   /* 
   vector<int> arr5;
   for(int i=0;i<7;i++){
    arr5.push_back(i);
   }
   vector<vector<int>> Carray;
   Carray= pairSum(arr5,7);
   for (auto& element : Carray) {
        for ( auto& num : element) {
            cout << num << " ";
        }
        cout <<endl;
    }*/
   /*
   vector<int> arr6;
   for(int i=1;i<9;i++){
    arr6.push_back(i);
   }
   vector<vector<int>> array= findTripletSum(arr6,12);
   vector<int>::iterator it;
   for(auto elem:array){
    for(auto num:elem){
      cout<<num<<" ";
    }
    cout<<endl;
   }
   */
   /*
   vector<int> aari ={0,1,1,0,0,1,0,1,0,1,0};
   sort01(aari);
   vector<int>::iterator it;
   for(it=aari.begin();it!=aari.end();it++){
    cout<<*it<<" ";
   }
   */
  /*
  int arr7[12]={0,1,1,2,1,2,1,2,0,0,2,0};
  sort012(arr7,12);
  printarr(arr7,12);
  */
 
 return 0;
}

