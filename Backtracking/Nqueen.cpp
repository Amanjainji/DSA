#include<bits/stdc++.h>
using namespace std;

// we are given a chess board and N queens ,place N queens such that no two queens attack each other

//Condition - no two queens should not be in same row , same column and attack each other in diagonal,.
//each row - 1 queen
//each column - 1 queen 


//N queens in NxN board , where 0 represent empty and 1 represent Queen position

void addSolution(vector<vector<int>> &board,vector<vector<int>> &ans,int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

//no attack condition
bool isSafe(int row,int col,vector<vector<int>> &board,int n){
    int x=row,y=col;
    //check for same row
    while(y>=0){
        if(board[x][y]==1){
            return false;
        }
        y--;
    }

    //no chance of being in same column

    //check for diagonal
    x=row;
    y=col;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        y--;
        x--;
    }

    x=row;
    y=col;
    while(x<n && y>=0){
        if(board[x][y]==1){
            return false;
        }
        y--;
        x++;
    }

    return true;
}
void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board ,int n){
    //base case
    if(col==n){
        addSolution(board,ans,n);
        return;
    }

    //solve 1 case and rest recursion will take place
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            //if placing queen is safe
            board[row][col]=1;
            solve(col+1,ans,board,n);

            //backtrack
            board[row][col]=0 ;
        }
    }
}
vector<vector<int>> nQueens(int n){
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;

    solve(0,ans,board,n);

    return ans;
}

int main(){
    vector<vector<int>> ans=nQueens(4);
    for(auto i: ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}