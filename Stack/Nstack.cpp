#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

class Nstack{
    private:
        int *arr;
        int *top;
        int *next;
        
        int n,s;
        int freespot;
    
    public:
        Nstack(int N,int S){
             n=N;
             s=S;
             arr=new int[s];
             top=new int[n];
             next=new int[s];

             //top initialise
            for(int i=0;i<n;i++){
                top[i]=-1;
            }
            //next initialise 
            for(int i=0;i<s;i++){
                next[i]=i+1;
            }

            //update last index value to -1
            next[s-1]=-1;

            //initialise freespot
            freespot=0; 
        }

        bool push(int x,int m){
            //check for overflow
            if(freespot==-1){
                return false;
            }

            //find index
            int index=freespot;

            //update freespot
            freespot=next[index];

            //insert element into array
            arr[index]=x;

            //update next
            next[index]=top[m-1];

            //update top
            top[m-1]=index;

            return true;
        }

        int pop(int m){

            //check underflow condition
            if(top[m-1]==-1)
                return -1;

            //get top index to pop
            int index=top[m-1];

            //update top
            top[m-1]=next[index];

            //update next
            next[index]=freespot;

            //update freespot
            freespot=index;

            return arr[index];


        }
};