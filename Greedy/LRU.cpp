#include <bits/stdc++.h>
using namespace std;

void LRUPageReplacement(vector<int> pages, int capacity) {
    unordered_map<int, int> lastUsed; // page -> last used index
    vector<int> frames;               // current pages in memory
    int faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];

        // Check if page already in memory
        auto it = find(frames.begin(), frames.end(), page);
        if (it != frames.end()) {
            // Page hit: update usage time
            lastUsed[page] = i;
        } else {
            // Page fault
            faults++;
            if (frames.size() < capacity) {
                frames.push_back(page);
            } else {
                // Find least recently used page
                int lruPage = frames[0];
                int minIndex = lastUsed[lruPage];
                for (int f : frames) {
                    if (lastUsed[f] < minIndex) {
                        minIndex = lastUsed[f];
                        lruPage = f;
                    }
                }
                // Replace it
                replace(frames.begin(), frames.end(), lruPage, page);
            }
            lastUsed[page] = i;
        }

        // Print current state of frames
        cout << "Step " << i+1 << " (page " << page << "): ";
        for (int f : frames) cout << f << " ";
        cout << (it == frames.end() ? " (Page Fault)" : " (Hit)") << "\n";
    }

    cout << "\nTotal Page Faults = " << faults << endl;
}

int main() {
    vector<int> pages = {7,0,1,2,0,3,0,4,2,3,0,3,2};
    int capacity = 4;

    LRUPageReplacement(pages, capacity);

    return 0;
}
