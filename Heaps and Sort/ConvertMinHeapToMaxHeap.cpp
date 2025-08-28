#include <bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted at index i in array arr[]
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2*i + 1;       // left child
    int right = 2*i + 2;      // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify
    }
}

// Function to convert min-heap to max-heap
void convertMinToMaxHeap(vector<int>& arr, int n) {
    // Start from last non-leaf node and heapify each node
    for (int i = (n/2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int n = arr.size();

    cout << "Min-Heap array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    convertMinToMaxHeap(arr, n);

    cout << "Max-Heap array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
