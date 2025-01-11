#include <iostream>
#include <string>

using namespace std;

void TowerofHanoi(int n,string S,string A,string D){
    if(n>0){
        TowerofHanoi(n-1,S,D,A);
        cout<<"from "<<S<<" to "<<D<<endl;
        TowerofHanoi(n-1,A,S,D); 
    }
}

int main(){
    int *arr=new int();
    for(int i=0;i<5;i++){
        arr[i]=i+1;
        cout<<arr[i]<<" ";
    }
    //TowerofHanoi(5,"Source","Auxillary","End");
}