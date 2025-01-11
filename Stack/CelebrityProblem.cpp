#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

//brute force approach - O(N^2)
int celebrityBrute(vector<vector<int>> &M,int n){
    int ans=-1;
    for(int i=0;i<n;i++){
        int know=0;
        for(int j=0;j<n;j++){
            if(i!=j){
                if(M[i][j]==1){
                know=1;
                break;
            }
          }
        } 
        if(!know){
                int flag=1;
                for(int j=0;j<n;j++){
                    if(i!=j){
                        if(M[j][i]==0){
                            flag=0;
                            break;
                        }
                    }
                }
                if(flag){
                    ans=i;
                }
            }
    }
    return ans;
}


// O(N) approach using stack
int celebrity(vector<vector<int>> &M,int n){
    stack<int> s;
    //step 1:push all element in stack
    for(int i=0;i<n;i++){
        s.push(i);
    }
    while(s.size()>1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(M[a][b]==1)         // a knows b , then a cannot be a celebrity
            s.push(b);
        else 
            s.push(a);
    }

    //step 3: single element in stack is a potential celebrity

    bool rowCheck=true;
    int key=s.top();

    for(int i=0;i<n;i++){
        if(i!=key && M[key][i]==1){
            rowCheck=false;
            break;
        }
    }

    bool colCheck=true;
    for(int i=0;i<n;i++){
        if(i!=key && M[i][key]==0){
            colCheck=false;
            break;
        }
    }

    if(rowCheck && colCheck){
        return key;
    }
    else{
        return -1;
    }
}


int main(){
    vector<vector<int>> M={{0,1,0},{0,0,0},{0,1,0}};
    cout<<celebrity(M,3);
}