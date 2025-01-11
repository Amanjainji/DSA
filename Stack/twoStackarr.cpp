#include<iostream>
using namespace std;
 

class TwoStack{
    //properties
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    //constructor
    TwoStack(int s){
        this->size=s;
        arr=new int[s];
        top1=-1;
        top2=s;
    }

    void push1(int num){
        if(top2-top1>1){
            top1++;
            arr[top1]=num;
        }
        else{
           cout<<"Stack Overflow!!"<<endl; 
        }
    }

    void push2(int num){
        if(top2-top1>1){
            top2--;
            arr[top2]=num;
        }
        else{
           cout<<"Stack Overflow!!"<<endl; 
        }
    }

    int pop1(){
        if(top1>=0){
            int ans=arr[top1];
            top1--;
            return ans;
        }
        else{
            cout<<"Underflow!!"<<endl;
            return -1;
        }
    }

    int pop2(){
        if(top2<size){
            int ans=arr[top2];
            top2++;
            return ans;
        }
        else{
            cout<<"Underflow!!"<<endl;
            return -1;
        }
    }
};

void printTwoStack(TwoStack s){

    for(int i=s.top1;i>=0;i--){
        cout<<s.arr[i]<<" ";
    }
    for(int j=s.top2;j<s.size;j++){
         cout<<s.arr[j]<<" ";
    }
    cout<<endl;
}

int main(){
    TwoStack s(10);
    s.push1(10);
    s.push1(12);
    s.push1(15);
    s.push1(19);
    s.push2(2);
    s.push2(3);

    printTwoStack(s);

    s.pop1();
    s.pop2();
    printTwoStack(s);

}