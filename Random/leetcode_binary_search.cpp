#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

/* Binary search */
//problem 1 : find first and last occurence of a number
//for eg: [1,2,3,3,3,3,4,5,6] ---> 3s first occurence is at 2nd index and last occurence is at 5th index
/*
int firstOccur(int arr[],int n,int key){
  int low=0,high=n-1;
  int mid = low + (high-low)/2;
  int ans=-1;

  while(low<=high){
    if(arr[mid]== key){
      ans=mid;
      high=mid-1;
    }
    else if(key>arr[mid]){
      low=mid+1;
    }
    else{
      high=mid-1;
    }
    mid=low+(high-low)/2;
  }
  return ans;
}


int lastOccur(int arr[],int n,int key){
  int low=0,high=n-1;
  int mid = low + (high-low)/2;
  int ans=-1;

  while(low<=high){
    if(arr[mid]== key){
      ans=mid;
      low=mid+1;
    }
    else if(key>arr[mid]){
      low=mid+1;
    }
    else{
      high=mid-1;
    }
    mid=low+(high-low)/2;
  }
  return ans;
}


pair<int,int> firstAndLastOccurences(int arr[],int n,int k){
  pair <int,int> p;
  p.first = firstOccur(arr,n,k);
  p.second = lastOccur(arr,n,k);

  return p;
}


int totalNumberOfOccurences(int arr[],int n,int k){
  int firstIndex= firstOccur(arr,n,k);
  int LastIndex= lastOccur(arr,n,k);

  int Total= LastIndex-firstIndex +1;
  return Total;
}
*/

// problem 2: peak Index of mountain array
/*
int peakIndexMountaineArray(vector<int> &arr){
  int s=0;
  int e=arr.size()-1;
  int mid=s + (e-s)/2;

  while(s<e){
    if(arr[mid] < arr[mid+1]){
      s=mid+1;
    }
    else{
      e=mid;
    }
    mid=s + (e-s)/2;
  }
  return mid;
}
*/
//problem 3:get Pivot using binary search
int getPivot(int arr[],int n){
  int s=0;
  int e=n-1;
  int mid=s+ (e-s)/2;
  while(s<e){
    if(arr[mid]>=arr[0]){
      s=mid+1;
    }
    else{
      e=mid;
    }
    mid=s+ (e-s)/2;
  }
  return s;
}
int binarySearch(int array[], int x, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}
//problem 4: search in a rotated sorted array
/*
int findPosition(int arr[],int size,int k){
  int pivot = getPivot(arr,size);
  if(k>= arr[pivot] && k<= arr[size-1]){
    //BS on 2nd line
    return binarySearch(arr,k,pivot,size-1);
  }
  else{
    //BS on 1st line
    return binarySearch(arr,k,0,pivot-1);
  }
}
*/

//problem 5: find square root of a number using binary search -- leetcode
/*
int mySqrt(int n){
  int s=0;
  int e=n;
  long long int mid=s+(e-s)/2;
  long long int ans=-1;

  while(s<=e){
    long long int square=mid*mid;
    if(square == n){
      return mid;
    }

    if(square<n){
      ans=mid;
      s=mid+1;
    }
    else{
      e=mid-1;
    }
    mid=s+(e-s)/2;
  }
  return ans;
}

double morePrecision(int n,int precision,int tempsol){
  double factor =1;
  double ans=tempsol;
  for(int i=0; i<precision;i++){
    factor = factor/10;
    for(double j=ans; j*j<n;j=j+factor){
      ans=j;
    }
  }
  return ans;
}
*/


/* //Book allocation Problem
bool isPossible(vector<int> arr, int n, int m, int mid){
  int studentCount =1;
  int pageSum =0;

  for(int i=0; i<n;i++){
    if(pageSum + arr[i]<=mid){
      pageSum+= arr[i];
    }
    else{
      studentCount++;
      if(studentCount>m || arr[i]>mid ){
          return false;
      }
      pageSum+=arr[i];
    }
  }
  return true;
}

int allocateBooks(vector <int> arr , int n , int m){
  int s=0; //n - represneting books and element at that index = pages// m- student
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=arr[i];
  }
  int e= sum;
  int ans=-1;
  int mid = s+(e-s)/2;

  while(s<=e){
    if(isPossible(arr,n,m,mid)){
      ans = mid;
      e=mid-1;
    }
    else{
      s=mid+1;
    }
    mid=s+(e-s)/2;
  }
  return ans;
}
*/

/* Painters Partition problem */
/*
bool ifPossiblePainterDistribution(vector<int> arr,int size,int painter,int mid ){
  int PainterCount =0;
  int boardSum =0;

  for(int i=0; i<size;i++){
    if(boardSum + arr[i]<=mid){
      boardSum+= arr[i];
    }
    else{
      PainterCount++;
      if(PainterCount>painter || arr[i]>mid ){
          return false;
      }
      boardSum+=arr[i];
    }
  }
  return true;
}

int PainterPartition(vector<int> arr,int size ,int painter){
  int s=0;
  int sum=0;
  for(int i=0;i<size;i++){
    sum+=arr[i];
  }
  int ans=-1;
  int e=sum;
  int mid=s+(e-s)/2;
  while(s<=e){
    if(ifPossiblePainterDistribution(arr,size,painter,mid)){  
      ans=mid;
      e=mid-1;
    }
    else{
      s=mid+1;
    }
    mid=s+(e-s)/2;
  }
  return ans;
}
*/

//aggressive cows
bool ifPossibleCows(vector<int> arr,int cows,int mid){
  int cowCount=1;
  int lastPos= arr[0];
  for(int i=0;i<arr.size();i++){
      if(arr[i]-lastPos>=mid){
        cowCount++;
        if(cowCount==cows){
          return true;
        }
        lastPos=arr[i];
      }
  }
  return false;
}
int aggressiveCows(vector<int> arr,int cows){
  sort(arr.begin(),arr.end());
  int s=0;
  int maxi=-1;
  for(int i=0;i<arr.size();i++){
    if(arr[i]>maxi) maxi=arr[i];
  }
  int e=maxi;
  int mid=s+(e-s)/2;
  int ans=-1;
  while(s<=e){
    if(ifPossibleCows(arr,cows,mid)){
      ans=mid;
      s=mid+1;
    }
    else{
      e=mid-1;
    }
    mid=s+(e-s)/2;
  }
  return ans;
}
int main(){
    int arr3[9]={1,2,3,3,3,3,4,5,6}; 
    int arr4[5]={7,9,1,2,3};
    int num=25;
//cout<<"first occurence at index "<<firstOccur(arr3,9,3)<<endl;
 //cout<<"last occurence at index "<<lastOccur(arr3,9,3)<<endl;
 /*
 pair<int,int> p;
 p=firstAndLastOccurences(arr3,9,3);
 cout<<p.first <<" " <<p.second<<endl;
 cout<<"Total Number of occurrences: "<<totalNumberOfOccurences(arr3,9,3);*/
/*
 vector<int> mountArr={1,5,7,10,6,2}; 
 int k=peakIndexMountaineArray(mountArr);
 cout<<"Peak element index:"<<k;
 */
/*
int numm=getPivot(arr4,5);
cout<<"Pivot is "<<arr4[numm]<<" at index "<<numm<<endl;
*/
//cout<<findPosition(arr4,5,2);
//int a= mySqrt(37);
//cout<<morePrecision(37,3,a);
/*
vector <int> books={10,20,30,40};
int NoOfStudent =2;
cout<<allocateBooks(books,4,NoOfStudent);
*/

//vector<int> Boards={5,15,20,30};
//int Painters=2;
//cout<<PainterPartition(Boards,4,Painters);

vector<int> arr={1,2,3,4,10};
int cows=3;
cout<<aggressiveCows(arr,cows);
return 0;
}
