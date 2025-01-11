#include <iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;
void printVector(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//problem 1: print wave form
/*
vector<int> wavePrint(int arr[][3],int row ,int col){
    int i=0;
    vector<int> ans;
    for(int c=0;c<col;c++){
        if(i%2==0){
            for(int r=0;r<col;r++){
            ans.push_back(arr[r][c]);
        }
        }
        else{
            for(int r=col-1;r>=0;r--){
            ans.push_back(arr[r][c]);
        }
        }
        i++;
    }
    return ans;
}*/

//problem 2: Spiral print (Amazon 3 times,leetcode 54)
/*
vector<int> spiralOrder(vector<vector<int>>& matrix){
     vector<int> ans;
     //as it is a vector inside vector
     int row=matrix.size();
     int col=matrix[0].size();

     int count=0;
     int total=row*col;

     //index initialize
     int startingRow=0;
     int startingCol=0;
     int endingRow=row-1;
     int endingCol=col-1;

     while(count < total){
        //print starting row
        for(int index=startingCol ; count < total &&index<=endingCol ;index++){
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        //print ending column
        for(int index=startingRow ;count < total && index<=endingRow ;index++){
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        //printing ending row
        for(int index=endingCol;count < total && index>=startingCol;index--){

        ans.push_back(matrix[endingRow][index]);
        count++;
        }
        endingRow--;

        //print starting Column
        for(int index=endingRow;count < total && index>=startingRow;index--){
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
     }
     return ans;
}
*/
bool BinarySearchRowSorted(vector<vector<int>> arr,int target){
    int row=arr.size();
    int col=arr[0].size();

    int s=0;
    int e=row*col-1;
    int mid= s+(e-s)/2;
    while(s<=e){
        if(arr[mid/col][mid%col]==target){
            return 1;
        }
        if(arr[mid/col][mid%col]<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid= s+(e-s)/2;
    }
    return 0;
}

bool BinarySearchBothSorted(vector<vector<int>> arr,int target){
    int rowSize=arr.size();
    int colSize=arr[0].size();

    int row=0;
    int col=colSize-1;

    while(row<rowSize && col>=0){
        if(arr[row][col]==target){
            return 1;
        }
        if(arr[row][col]<target){
            row++;
        }
        else{
            col--;
        }
    }
 return 0;
}

void rotate901(vector<vector<int>> &arr){
    int row=arr.size();
    int col=arr[0].size();
    vector<vector<int>> temp;
    for(int i=0;i<arr.size();i++){
        temp.push_back(arr[i]);
    }
    int count=0;
    int total=row*col-1;

    int rowStart=0;
    int colStart=0;
    int rowEnd=row-1;
    int colEnd=col-1;

    while(count<total){
        for(int i=colStart;i<colEnd;i++){
            arr[rowStart][i]=temp[rowEnd-i][colStart];
            count++;
        }
        rowStart++;
        for(int i=rowStart;i<=rowEnd;i++){
            arr[i][colEnd]=temp[rowStart-1][i];
            count++;
        }
        colEnd--;
        for(int i=colEnd;i>=colStart;i--){
            arr[rowEnd][i]=temp[rowEnd-i][colEnd];
            count++;
        }
        rowEnd--;
        for(int i=rowEnd;i>=rowStart;i--){
            arr[i][colStart]=temp[rowEnd+1][i];
            count++;
        }
        colStart++;
    }
}
void rotate90(vector<vector<int>>& arr) {
    int row = arr.size();
    if (row == 0) return; 
    int col = arr[0].size();
    vector<vector<int>> temp = arr;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[j][row - i - 1] = temp[i][j]; 
        }
    }
}

int main(){

    int arr1[3][3]={1,2,3,4,5,6,7,8,9};
    //printVector(wavePrint(arr,3,3));
    vector<vector<int>> k={{1,2,3},{4,5,6},{7,8,9}};
    //vector<int> v=spiralOrder(k);
    //printVector(v);
    rotate90(k);
    /*
    for(int i=0;i<k.size();i++){
        for(int j=0;j<k[0].size();j++){
            cout<<k[i][j]<<" ";
        }
    }*/


//pointers
    char ch[6]="abcde";
    char *c=ch;
    //cout<<*(c+1)<<endl;


    //dynamic 2D array
    int row=5;
    int col=4;
    int **arr= new int*[row];
    for(int i=0;i<row;i++){
        arr[i]=new int[col];
    }



    
    return 0;
}