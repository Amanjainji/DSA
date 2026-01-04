#include <bits/stdc++.h>
using namespace std;

// Counting sort based on a specific digit (place)
void countingSort(vector<int>& arr, int place) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    // Count occurrences of digits
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / place) % 10;
        count[digit]++;
    }

    // Cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (stable sort)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / place) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back to original array
    arr = output;
}

// Radix Sort function
void radixSort(vector<int>& arr) {
    int mx = *max_element(arr.begin(), arr.end());

    // Sort for every digit place
    for (int place = 1; mx / place > 0; place *= 10) {
        countingSort(arr, place);
    }
}

// Print array
void printArray(const vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {121, 432, 564, 23, 1, 45, 788};

    radixSort(arr);
    printArray(arr);

    return 0;
}
