#include <bits/stdc++.h>
using namespace std;

void bucketSort(float arr[], int n) {
    // 1. Create n empty buckets
    vector<float> buckets[n];

    // 2. Put elements into different buckets
    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];   // bucket index
        buckets[idx].push_back(arr[i]);
    }

    // 3. Sort each bucket
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 4. Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float val : buckets[i]) {
            arr[index++] = val;
        }
    }
}

int main() {
    float arr[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
