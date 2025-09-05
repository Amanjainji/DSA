#include<bits/stdc++.h>
 using namespace std;
 
 int countPlatforms(int n,int arr[],int dep[])
 {
    sort(arr,arr+n);
    sort(dep,dep+n);
 
    int ans=1;
    int count=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]) //one more platform needed
        {
            count++;
            i++;
        }
        else //one platform can be reduced
        {
            count--;
            j++;
        }
        ans=max(ans,count); //updating the value with the current maximum
    }
    return ans;
 }
 
 int main()
 {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    /*
Step-by-step:

Train arrives at 900 → count=1 (ans=1)

Train arrives at 945 → count=2 (ans=2)

Train arrives at 955 → count=3 (ans=3)

Train departs at 920 → count=2

Train arrives at 1100 → count=3

Train departs at 1130 → count=2

Train departs at 1150 → count=1

Train departs at 1200 → count=0

Train arrives at 1500 → count=1

Train arrives at 1800 → count=2

Train departs at 1900 → count=1

Train departs at 2000 → count=0

👉 Maximum = 3 platforms
    */
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
 }
