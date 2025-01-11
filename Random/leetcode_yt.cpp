#include <iostream>
#include <cmath>
using namespace std;

// 1st problem 
/*
int reverse(int x){
    int ans=0;
    while(x!=0){
    if((ans > INT32_MAX/10) || (ans < INT32_MIN/10 )){
        return 0;
    }
        int digit =x%10;
        ans=(ans*10)+ digit;
        x=x/10;
    }
    return ans;
}
int main(){
    int rev=reverse(1254545);
    cout<<rev;
    return 0;
}

*/

/*
// 2nd problem question 
int bitwiseComplement(int n){
    int m=n;  //like n=5 or 101
    int mask=0;

    if(n==0){  //edge case as 0 complement is 1
        return 1;
    }

    while(m!=0){
        mask=(mask<<1)|1;  //then mask should be 0000000000000111
        m=m>>1;
    }

    int ans = (~n) & mask;  //1111...010 & 0000...111 = 0000...010
    return ans; //010= 2 in base 10
} 
int main(){
    int num=bitwiseComplement(5);
    cout<<num;
    return 0;
}
*/
 
//3RD PROBLEM
/*
int ans=1;
bool isPowerOfTwo(int n){
    for (int i=0 ; i<=30 ;i++){
        if (ans==n){
            return true;
        }
        if(ans<INT32_MAX/2){
            ans*=2;
        }

    }
    return false;
}

int main(){
   bool value=isPowerOfTwo(14);
   cout<<value;
}
*/