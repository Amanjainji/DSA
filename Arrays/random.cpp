#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;
void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void printVector(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
vector<int> reverse(vector<int> v){
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
        i--;
        j--;
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

}*/

   
/*
void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
    vector<int> arr3;
    int i=0,j=0;
    while((i<n && j<m)){
        if(arr1[i]>arr2[j]){
            arr3.push_back(arr2[j]);
            j++;
            
        }
        else{
            arr3.push_back(arr1[i]);
            i++;
            
        }
    }
    while(i<n){
        arr3.push_back(arr1[i]);
        i++;
        
    }
    while(j<m){
        arr3.push_back(arr2[j]);
        j++;
        
    }
    arr1=arr3;
};
*/
 bool search(vector<char> s,char ch){
        for(int i=0;i<s.size();i++){
            if(s[i]==ch){
                return true;
            }
        }
        return false;
    }
int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0;
        int count=0;
        vector<char> sub;
        while(i<n){
            for(int j=i;j<n;j++){
                if(search(sub,s[j])){
                    break;
                }
                sub.push_back(s[j]);
            }
            if(sub.size()>count){
                count=sub.size();
            }
            sub.clear();
            i++;
        }   
        return count;  
    }

int myAtoi(string s) {
        int i;
        int ans=0;
        int j=1;
        for( i=0;i<s.length();i++){
            while(s[i]==' '){
                i++;
            }
            if(s[i]=='-'){
                i++;
            }
            if(s[i]>='0' && s[i]<='9' ){
                int k=s[i];
                ans=ans*10+k;
            }
        }
    }

long long countOperationsToEmptyArray(vector<int>& nums) {
        long long count =0;
        int n=nums.size();
        int min=0;
        while(n>0){
            for(int i=0;i<n;i++){
                if(nums[i]<nums[min]){
                    min=i;
                }
            }
            if(min!=0){
                int k=nums[0];
                nums.erase(nums.begin());
                nums.push_back(k);
                count++;
            }
            else{ 
                nums.erase(nums.begin());
                n--;
                count++;
            }
        }
        return count;
    }


int main(){
    vector<int> array1={-15,-19,5};
    vector<int> array2={2,6,7};
    cout<<countOperationsToEmptyArray(array1);
    //string s="pwwkew";
    //cout<<lengthOfLongestSubstring(s);

    //vector<int> SUM;
    //SUM=findArraySum(array1,array2);
    //merge(array1,4,array2,3);
    //printVector(array1);
}
