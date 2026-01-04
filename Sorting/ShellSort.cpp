#include <bits/stdc++.h>
using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();

    // Start with a big gap, then reduce it
    for (int gap = n / 2; gap > 0; gap /= 2) {

        // Do insertion sort for this gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            // Shift earlier gap-sorted elements up
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Put temp in correct place
            arr[j] = temp;
        }
    }
}

int main() {
    vector<int> arr = {23, 12, 1, 8, 34, 54, 2, 3};

    shellSort(arr);

    cout << "Sorted array:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
