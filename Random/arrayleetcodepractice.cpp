#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void printArr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void printVector(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
/*
void rotateArrayOnce(int arr[],int size){  //self maded
    int last=arr[size-1];
    int temp[size];
    for(int i=0;i<=size;i++){
        temp[i]=arr[i];
    }
    for(int i=0;i<=size-2;i++){
        arr[i+1]=temp[i];
    }
    arr[0]=last;
}

//by sir
void rotateVector(vector<int> &nums,int k){ //k = no.of rotation
    vector<int> temp(nums.size());

    for(int i=0;i<nums.size();i++){
        temp[(i+k)%nums.size()] = nums[i];
    }

    //copy temp into nums vector
    nums=temp;
}
*/
/*
bool checkSortedRotated(vector<int> nums){
    int count=0;
    int n=nums.size();
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]>nums[i]){
            count++;
        }
    }
    if(nums[n-1]>nums[0]){
        count++;
    }
    return count<=1;
}
*/
vector<int> reverseVector(vector<int> v){
    int s=0;
    int e=v.size()-1;

    while(s<e){
        swap(v[s++],v[e--]);
    }
    return v;
}
/*
vector<int> findArraySum(vector<int> &a,vector<int> &b){
    int n=a.size();
    int m=b.size();
    int i=n-1;
    int j=m-1;
    vector<int> ans;
    int carry=0;

    while(i>=0 && j>=0){
        int val1= a[i];
        int val2 = b[j];
        int sum=val1+val2+ carry;

        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;j--;
    }

    //case 1: some numbers in array a[] is left
    while(i>=0){
        int sum=a[i]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
    }
    //case 2: some numbers in array b[] is left
    while(j>=0){
        int sum=b[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        j--;
    }

    //case 3: carry is left (eg. 999 + 9=1008)
    while(carry!=0){
        int sum=carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
    }

    return reverseVector(ans);

}
*/
//reverse the array from a particular index
/*
vector<int> ReverseTheArray(vector<int> arr,int index){
    int s=index+1;
    int e=arr.size()-1;

    while(s<e){
        swap(arr[s++],arr[e--]);
    }
    return arr;
}*/
/*
vector<int> MergeSortedVectors(vector<int> arr1,vector<int> arr2){
    vector<int> ans;
    for(int i=0;i<arr1.size();i++){
        ans.push_back(arr1[i]);
    }
    for(int i=0;i<arr2.size();i++){
        ans.push_back(arr2[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
*/
/*
int* MergeSortedArray(int arr1[],int n,int arr2[],int m){
    int size=m+n;
    int* arr3 = new int[size];
    int i=0,j=0,k=0;
    while((i<n && j<m)){
        if(arr1[i]>arr2[j]){
            arr3[k]=arr2[j];
            j++;
            k++;
        }
        else{
            arr3[k]=arr1[i];
            i++;
            k++;
        }
    }
    while(i<n){
        arr3[k]=arr1[i];
        i++;
        k++;
    }
    while(j<m){
        arr3[k]=arr2[j];
        j++;
        k++;
    }
    return arr3;
}
*/
//self maded:
/*
vector<int> MoveZeroes(vector<int>& arr){
    int count=0;
    vector<int> ans;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            count++;
        }
        else{
            ans.push_back(arr[i]);
        }
    }
    while(count>0){
        ans.push_back(0);
        count--;
    }

    return ans;
}

void MoveZeroesSir(vector<int> &nums){
    int i=0;
    for(int j=0; j<nums.size();j++){
        if(nums[j]!=0){
            swap(nums[j],nums[i]);
            i++;
        }
    }
}
*/

int main(){
    int arr[7]={1,2,3,4,5,6,7};
    //rotateArrayOnce(arr,7);
    //printArr(arr,7);

    vector<int> array={1,2,3,4,5,6,7};
    //rotateVector(array,2);
    //printVector(array);

    vector<int> array1={9,9,9};
    //cout<<checkSortedRotated(array1);
    vector<int> array2={9};
    //vector<int> SUM=findArraySum(array1,array2);

    //printVector(SUM);

    //vector<int> ans=ReverseTheArray(array,3);
    //printVector(ans);

    vector<int> array3={1,2,5,7};
    vector<int> array4={3,4,6};
    //vector<int> ans1=MergeSortedVectors(array3,array4);
    //printVector(ans1);

    int array5[4]={1,2,5,7};
    int array6[4]={3,4,4,6};
    /* int *ptr=MergeSortedArray(array5,4,array6,4);
    for(int i=0;i<8;i++){
        cout<<*(ptr+i)<<" ";
    }
    */
    vector<int> array7={1,2,0,0,5,0,7};
    //printVector(MoveZeroes(array7));
    //MoveZeroesSir(array7);
    //printVector(array7);

    return 0;
}