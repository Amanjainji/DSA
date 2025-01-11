#include<bits/stdc++.h>
using namespace std;

// we are given a chess board and N queens ,place N queens such that no two queens attack each other

//Condition - no two queens should not be in same row , same column and attack each other in diagonal,.
//each row - 1 queen
//each column - 1 queen 


//N queens in NxN board , where 0 represent empty and 1 represent Queen position


//Optimisation in inSafe function by reducing row and diagonal time to O(1) from O(n):
/*
 1)row by hashMap :
  map<row,bool> //bool is true if row have a queen
 2)anti diagonal hashmap:
  map<row+col,bool> //bool is true if it have a queen
 3)diagonal hashmap :
  map<(n-1+col-row),true>  //bool is true if it have a queen.
*/
void addSolution(vector<vector<int>> &board,vector<vector<string>> &ans,int n){
    vector<string> temp;
    for(int i=0;i<n;i++){
        string k="";
        for(int j=0;j<n;j++){
            if(board[i][j]==0){
                k+='.';
            }
            else{
                k+='Q';
            }
        }
        temp.push_back(k);
    }
    ans.push_back(temp);
}

//no attack condition
bool isSafe(int row,int col,vector<vector<int>> &board,int n,unordered_map<int ,bool> forRow,unordered_map<int ,bool> forAntiDiagonal,unordered_map<int ,bool> forDiagonal){
    int x=row,y=col;
    //check for same row
    if(forRow[x]==1 && forRow.find(x)!=forRow.end()){
        return false;
    }
    //no chance of being in same column

    //check for anti - diagonal
    if(forAntiDiagonal[x+y]==1 && forAntiDiagonal.find(x+y)!=forAntiDiagonal.end()){
        return false;
    }

    //check for diagonal
    if(forDiagonal[(n-1)+y-x]==1 && forDiagonal.find((n-1)+y-x)!=forDiagonal.end()){
        return false;
    }
    return true;
}


void solve(int col,vector<vector<string>> &ans,vector<vector<int>> &board ,int n,unordered_map<int ,bool> &forRow,unordered_map<int ,bool> &forAntiDiagonal,unordered_map<int ,bool> &forDiagonal){
    //base case
    if(col==n){
        addSolution(board,ans,n);
        return;
    }
    
    //solve 1 case and rest recursion will take place
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n,forRow,forAntiDiagonal,forDiagonal)){
            //if placing queen is safe
            board[row][col]=1;
            forRow[row]=true;
            forAntiDiagonal[row+col]=true;
            forDiagonal[(n-1)+col-row]=true;
            
            //Recursion
            solve(col+1,ans,board,n,forRow,forAntiDiagonal,forDiagonal);

            //backtrack
            board[row][col]=0 ;
            forRow[row]=false;
            forAntiDiagonal[row+col]=false;
            forDiagonal[(n-1)+col-row]=false;
        }
    }
}
vector<vector<string>> nQueens(int n){
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<string>> ans;
    unordered_map<int ,bool> forRow;
    unordered_map<int ,bool> forAntiDiagonal;
    unordered_map<int ,bool> forDiagonal;

    solve(0,ans,board,n,forRow,forAntiDiagonal,forDiagonal);

    return ans;
}

//TC - O(N!)    SC - O(N^2)
int main(){
    vector<vector<string>> ans=nQueens(4);
    for(auto i: ans){
        for(auto j:i){
            cout<<j<<"      ";
        }
        cout<<endl;
    }
}