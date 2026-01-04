#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return;

    // 1. Find min and max
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    // 2. Create buckets
    int bucketCount = n;
    vector<vector<int>> buckets(bucketCount);

    // 3. Distribute elements into buckets
    for (int x : arr) {
        int idx = (long long)(x - minVal) * bucketCount / (maxVal - minVal + 1);
        buckets[idx].push_back(x);
    }

    // 4. Sort each bucket
    for (int i = 0; i < bucketCount; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 5. Merge buckets
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int x : buckets[i]) {
            arr[index++] = x;
        }
    }
}

int main() {
    vector<int> arr = {42, -10, 33, 25, 60, 15, 5};

    bucketSort(arr);

    cout << "Sorted array:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
