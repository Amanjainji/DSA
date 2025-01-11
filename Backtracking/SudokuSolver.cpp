#include<bits/stdc++.h>
using namespace std;
/*
Problem statement
You have been given a 9x9 2d integer matrix representing a Sudoku puzzle. The empty cells of the Sudoku are filled with 0s, and the rest of the cells are filled with integers from 1 to 9. Your task is to fill all the empty cells such that the final matrix represents a Sudoku solution.

Note:
A Sudoku solution must satisfy all the following conditions-
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub-grids of the grid.

*/

bool isSafe(int row,int col,vector<vector<int>> &board,int val){
    for(int i=0;i<board.size();i++){
        //row check
        if(board[row][i]==val)
            return false;
        
        //col check
        if(board[i][col]==val)
            return false;
        
        //3*3 matrix check
        if(board[3*(row/3) + i/3][3*(col/3)+i%3]==val)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board){
    int n=board[0].size();
    for(int row=0;row<n ; row++){
        for(int col=0; col<n;col++){
            //cell empty
            if(board[row][col]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col]=val;
                        //recursive call
                        bool nextSolutionPossible=solve(board);
                        if(nextSolutionPossible){
                            return true;
                        }
                        else{
                            //backtrack
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}


//TC - O(9^m)   SC - O(1)     
//m=no.of emoty cells and SpaceComplexity is constant as maxStack calls is 81 fixed and constant
int main(){
    vector<vector<int>> board={
    {3,0,6,5,7,8,0,9,2},
    {5,2,9,1,3,4,7,6,8},
    {4,8,0,6,2,9,5,3,1},
    {2,6,3,4,1,5,9,8,7},
    {9,7,4,8,6,3,1,2,5},
    {8,5,1,7,9,2,6,4,3},
    {1,3,8,9,4,7,2,5,6},
    {6,9,2,3,5,0,8,7,4},
    {7,4,5,2,8,6,3,1,9}

    };
    cout<<solve(board);
}

