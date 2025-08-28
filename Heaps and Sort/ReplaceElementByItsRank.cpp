#include<bits/stdc++.h>
using namespace std;

/*
Replace elements by its rank in the array

Problem Statement: Given an array of N integers, the task is to replace each element of the array by its rank in the array.

Examples:

Example 1:
Input: 20 15 26 2 98 6
Output: 4 3 5 1 6 2
Explanation: When sorted,the array is 2,6,15,20,26,98. So the rank of 2 is 1,rank of 6 is 2,rank of 15 is 3 and so…

Example 2:
Input: 1 5 8 15 8 25 9
Output: 1 2 3 5 3 6 4
Explanation: When sorted,the array is 1,5,8,8,9,15,25. So the rank of 1 is 1,rank of 5 is 2,rank of 8 is 3 and so…
*/

//brute force TC - O(N^2)
vector<int> replaceByRank(int n,int *arr){
    vector<int> rank;
	for (int i = 0; i < n; i++) {
		set<int>s;
		for (int j = 0; j < n; j++) {
			if (arr[j] < arr[i]) {
				s.insert(arr[j]);
			}
		}
		rank.push_back(s.size()+1);
	}
    return rank;
}

//optimal approach - TC - O(N Log N)
vector<int> replaceByRank2(int n,int *arr) {
    // Min heap to store {value, index}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

    // Push all elements with their index
    for (int i = 0; i < n; i++) {
        minHeap.push({arr[i], i});
    }

    vector<int> rankArr(n);
    int rank = 1;

    // Assign ranks based on heap order
    while (!minHeap.empty()) {
        int idx=minHeap.top().second;
        minHeap.pop();

        rankArr[idx] = rank++;
    }

    return rankArr;
}

int main(){
    int n = 6;
	int arr[n] = {20, 15, 26, 2, 98, 6};
    vector<int> k= replaceByRank2(n,arr);
    for(auto i: k){
        cout<<i<<" ";
    }
}