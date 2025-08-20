#include<bits/stdc++.h>
using namespace std;

int main(){
    int N=13;   //1101
    int i=2;    //3210 bit position

    //1. check the ith bit is set or not
    if((N & 1<<i)!=0) cout<<"Set"<<endl;

    if((N>>i & 1)==1) cout<<"set"<<endl;


    //2 set the ith bit
    int n=13;
    i=1;
    n=n|(1<<i);
    cout<<n<<endl;

    //3 clear the ith bit
    n= n& ~(1<<i);
    cout<<n<<endl;

    //4 toggle the ith bit
    n=n^(1<<i);
    cout<<n<<endl;

    //5 remove the rightmost set bit
    n= n&(n-1);
    cout<<n<<endl;

    //6 check if the number is power of 2 or not
    n=16;
    if((n & (n-1))==0) cout<<"power of 2"<<endl;
    return 0;
}