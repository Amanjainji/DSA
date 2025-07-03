#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> adj(26), transpose(26);
vector<bool> visited(26);
stack<int> st;
vector<int> component(26, -1);

// DFS to fill stack - topological
void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs1(v);
    st.push(u);
}

// DFS to assign component ID
void dfs2(int u, int id) {
    component[u] = id;
    for (int v : transpose[u])
        if (component[v] == -1)
            dfs2(v, id);
}

vector<string> maxNumOfSubstrings(string s) {
    int n = s.size();
    vector<int> l(26, n), r(26, -1);

    // Step 1: First and last occurrence of each character
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';
        l[c] = min(l[c], i);
        r[c] = max(r[c], i);
    }

    // Step 2: Build character dependency graph
    for (int c = 0; c < 26; ++c) {
        if (l[c] > r[c]) continue;
        for (int i = l[c]; i <= r[c]; ++i) {
            int d = s[i] - 'a';
            if (c != d) {
                adj[c].push_back(d);     // c → d
                transpose[d].push_back(c);     // reverse graph
            }
        }
    }

    // Step 3: Kosaraju's algorithm
    for (int i = 0; i < 26; ++i)
        if (!visited[i] && l[i] <= r[i])
            dfs1(i);

    /*
    id- This is a counter for assigning unique component IDs to each SCC. It starts at 0 and increases by 1 each time a new SCC is found.
    */
    int id = 0;
    while (!st.empty()) {
        int u = st.top(); 
        st.pop();
        /*
        vector<int> component(26, -1) This keeps track of which component each character belongs to.
        If component[c] = 2, that means character 'a' + c belongs to component 2.
        It is initially -1 for all 26 letters to indicate they are unassigned.
        */
        if (component[u] == -1) //done on the basis of transpose graph
            dfs2(u, id++);
    }

    // Step 4: For each component, get the total range
    vector<int> comp_l(id, n), comp_r(id, -1);
    for (int i = 0; i < 26; ++i) {
        if (l[i] > r[i]) continue;
        int cid = component[i];
        comp_l[cid] = min(comp_l[cid], l[i]);
        comp_r[cid] = max(comp_r[cid], r[i]);
    }

    vector<pair<int, int>> ranges;
    for (int i = 0; i < id; ++i)
        ranges.push_back(make_pair(comp_l[i], comp_r[i]));

    // Step 5: Sort by right end to apply greedy selection
    sort(ranges.begin(), ranges.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });

    // Step 6: Select non-overlapping substrings
    vector<string> res;
    int last_end = -1;
    for (auto&i : ranges) {
        int start=i.first,end=i.second;
        if (start > last_end) {
            res.push_back(s.substr(start, end - start + 1));
            last_end = end;
        }
    }

    return res;
}

// Example Usage
int main() {
    string s="abbaccd";
    vector<string> result = maxNumOfSubstrings(s);
    for (string& str : result)
        cout << str << endl;
    return 0;
}

/*
Let’s do a dry‐run of your algorithm on the example

string s = "abbaccd";

with indices labeled:

| index |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
|  char |  a  |  b  |  b  |  a  |  c  |  c  |  d  |


### 1. Compute `l[c]` and `r[c]` (first/last occurrences)

| character | code `c` |             `l[c]`            | `r[c]` |
| :-------: | :------: | :---------------------------: | :----: |
|     a     |     0    |               0               |    3   |
|     b     |     1    |               1               |    2   |
|     c     |     2    |               4               |    5   |
|     d     |     3    |               6               |    6   |
|    e…z    |    ≥4    | initialized so `l>r`, ignored |        |


 2. Build the dependency graph

For each character c with range [l[c],r[c]], we look at every position in that interval and add edges


c to (s[i]-'a'])


if it’s a different letter.

a (`c=0`), range [0..3] covers “a b b a” → sees ‘b’, so,
    0 to 1

* **b** (`c=1`), range [1..2] covers “b b” → only itself → no cross‐edges
* **c** (`c=2`), range [4..5] covers “c c” → only itself
* **d** (`c=3`), range [6..6] covers “d” → only itself

So the only nontrivial edge is 0 to 1.

3. Kosaraju’s SCC on this 4‐node subgraph

We only care about nodes 0–3 (a–d).  Since there are no mutual edges, each letter ends up in its own strongly connected component:

| letter | `component[letter]` |
| :----: | :-----------------: |
|  a (0) |          0          |
|  b (1) |          1          |
|  c (2) |          2          |
|  d (3) |          3          |

(so `id == 4` at the end)

### 4. Compute each component’s full span

```cpp
vector<int> comp_l(id, n), comp_r(id, -1);
// id = 4, n = 7
```

Loop over each letter $i=0\ldots3$:

* For **a** (comp 0):


    comp_l[0] = min(7,l[0]=0) = 0,
    comp_r[0] = max(-1,r[0]=3) = 3

* For **b** (comp 1):


    comp_l[1] = min(7,1) = 1,
    comp_r[1] = max(-1,2) = 2

* For **c** (comp 2):

  
    comp_l[2] = min(7,4) = 4,
    comp_r[2] = max(-1,5) = 5
 
* For **d** (comp 3):


    comp_l[3] = min(7,6) = 6,
    comp_r[3] = max(-1,6) = 6
  

So the component intervals are:

```
comp 0: [0,3]   → "abba"
comp 1: [1,2]   → "bb"
comp 2: [4,5]   → "cc"
comp 3: [6,6]   → "d"
```

---

### 5. Sort by end‐index for greedy

We collect

```cpp
ranges = { {0,3}, {1,2}, {4,5}, {6,6} }
```

and sort by the second element (the right endpoint):

```
sorted ranges = [ {1,2}, {0,3}, {4,5}, {6,6} ]
```

---

### 6. Greedy select non‐overlapping

Walk through sorted intervals, keeping track of `last_end = -1`:

1. {1,2}: start=1 > -1 → **take** “bb”, set `last_end=2`
2. {0,3}: start=0 ≤ 2 → skip
3. {4,5}: start=4 > 2 → **take** “cc”, set `last_end=5`
4. {6,6}: start=6 > 5 → **take** “d”,  set `last_end=6`

### Final result

```cpp
res = { "bb", "cc", "d" };
```
*/