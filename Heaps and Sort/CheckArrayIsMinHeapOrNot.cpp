#include <bits/stdc++.h>
using namespace std;

// Function to check if array is a Min-Heap
bool isMinHeap(vector<int>& arr, int n) {
    // Only need to check non-leaf nodes
    for (int i = 0; i <= (n-2)/2; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;

        // Check left child
        if (left < n && arr[i] > arr[left])
            return false;

        // Check right child
        if (right < n && arr[i] > arr[right])
            return false;
    }
    return true;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7, 9, 2};  // Not Min-Heap
    vector<int> arr2 = {10, 15, 14, 25, 30}; // Min-Heap

    cout << "arr1 is " << (isMinHeap(arr1, arr1.size()) ? "a Min-Heap\n" : "NOT a Min-Heap\n");
    cout << "arr2 is " << (isMinHeap(arr2, arr2.size()) ? "a Min-Heap\n" : "NOT a Min-Heap\n");

    return 0;
}
