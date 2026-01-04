#include <iostream>
#include <vector>
using namespace std;

//prefix[i][j] = arr[i][j] + prefix[i-1][j]  + prefix[i][j-1] - prefix[i-1][j-1]
vector<vector<int>> prefixSum2D(vector<vector<int>> &arr) {
    
    // number of rows
    int n = arr.size();
    
    // number of columns
    int m = arr[0].size();
    
    vector<vector<int>> prefix(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            // Start with original value
            prefix[i][j] = arr[i][j];
            
            // Add value from top cell if it exists
            if (i > 0) {
                prefix[i][j] += prefix[i - 1][j];
            }
            
            // Add value from left cell if it exists
            if (j > 0) {
                prefix[i][j] += prefix[i][j - 1];
            }
            
            // Subtract overlap from top-left diagonal if it exists
            if (i > 0 && j > 0) {
                prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
    }

    return prefix;
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    vector<vector<int>> prefix = prefixSum2D(arr);

    for (int i = 0; i < prefix.size(); i++) {
        for (int j = 0; j < prefix[0].size(); j++) {
            cout << prefix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}