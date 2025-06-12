# 🧠 DSA Patterns Cheat Sheet (with Simple Explanations) (ChatGPT :0)

## 🔁 1. Two Pointers

**Used When:** The array/string is sorted or you want to find subarrays, pairs, or move in opposite directions.

- **Problems:**
  - Find pair with sum in sorted array
  - Reverse a string or array in-place
  - Remove duplicates

**Template:**

```cpp
int left = 0, right = n - 1;
while (left < right) {
  // do something
  if (condition) right--;
  else left++;
}
```

---

## 🔂 2. Sliding Window

**Used When:** You're working with subarrays or substrings of fixed or variable length.

- **Problems:**
  - Maximum sum of subarray of size K
  - Longest substring without repeating characters

**Template:**

```cpp
int windowStart = 0;
for (int windowEnd = 0; windowEnd < n; windowEnd++) {
  // expand the window
  while (condition) {
    // shrink the window
    windowStart++;
  }
}
```

---

## 🔄 3. Fast & Slow Pointers (Floyd's Cycle)

**Used When:** Detecting cycles in linked lists or arrays.

- **Problems:**
  - Detect cycle in linked list
  - Find cycle start

**Template:**

```cpp
ListNode *slow = head, *fast = head;
while (fast && fast->next) {
  slow = slow->next;
  fast = fast->next->next;
  if (slow == fast) break;
}
```

---

## 🧮 4. Prefix Sum / Difference Array

**Used When:** Need fast range sum queries or updates.

- **Problems:**
  - Range sum query
  - Subarray sum equals K

**Prefix Sum Template:**

```cpp
vector<int> prefix(n+1);
prefix[0] = 0;
for (int i = 1; i <= n; i++)
  prefix[i] = prefix[i-1] + arr[i-1];
```

---

## 🔁 5. Recursion + Backtracking

**Used When:** Generating all combinations/permutations/paths.

- **Problems:**
  - Subsets / combinations
  - N-Queens
  - Sudoku solver

**Template:**

```cpp
void solve(int i, vector<int>& current) {
  if (i == nums.size()) {
    result.push_back(current);
    return;
  }
  // include
  current.push_back(nums[i]);
  solve(i + 1, current);
  current.pop_back();
  // exclude
  solve(i + 1, current);
}
```

---

## 🧵 6. Binary Search

**Used When:** Search in sorted arrays or find boundaries.

- **Problems:**
  - Search in sorted array
  - Find first/last occurrence

**Template:**

```cpp
int low = 0, high = n - 1;
while (low <= high) {
  int mid = low + (high - low) / 2;
  if (arr[mid] == target) return mid;
  else if (arr[mid] < target) low = mid + 1;
  else high = mid - 1;
}
```

---

## 🧱 7. Dynamic Programming (DP)

**Used When:** Overlapping subproblems + optimal substructure.

- **Problems:**
  - Fibonacci
  - Knapsack / Subset sum
  - Longest common subsequence

**Memoization Template:**

```cpp
int dp[1001];
int fib(int n) {
  if (n <= 1) return n;
  if (dp[n] != -1) return dp[n];
  return dp[n] = fib(n-1) + fib(n-2);
}
```

**Tabulation Template:**

```cpp
vector<int> dp(n+1);
dp[0] = 0; dp[1] = 1;
for (int i = 2; i <= n; i++)
  dp[i] = dp[i-1] + dp[i-2];
```

---

## 🌲 8. Tree Traversal

**Used When:** Solving tree-based problems.

- **Problems:**
  - Inorder, preorder, postorder
  - Level order
  - Depth-first and breadth-first search

**DFS Template:**

```cpp
void dfs(TreeNode* node) {
  if (!node) return;
  dfs(node->left);
  dfs(node->right);
}
```

**BFS Template:**

```cpp
queue<TreeNode*> q;
q.push(root);
while (!q.empty()) {
  auto node = q.front(); q.pop();
  if (node->left) q.push(node->left);
  if (node->right) q.push(node->right);
}
```

---

## 🔗 9. Graph Traversal (DFS/BFS)

**Used When:** Traversing connected components, finding paths, detecting cycles.

- **Problems:**
  - Number of islands
  - Bipartite graph
  - Topological sort

**DFS Graph Template:**

```cpp
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
  visited[node] = true;
  for (int nei : adj[node]) {
    if (!visited[nei]) dfs(nei, adj, visited);
  }
}
```

**BFS Graph Template:**

```cpp
queue<int> q;
q.push(start);
visited[start] = true;
while (!q.empty()) {
  int node = q.front(); q.pop();
  for (int nei : adj[node]) {
    if (!visited[nei]) {
      visited[nei] = true;
      q.push(nei);
    }
  }
}
```

---

## 🏗 10. Union Find (Disjoint Set Union - DSU)

**Used When:** Finding connected components, Kruskal’s MST, cycle detection.

**Template:**

```cpp
vector<int> parent(n);
for (int i = 0; i < n; i++) parent[i] = i;

int find(int x) {
  if (parent[x] != x) parent[x] = find(parent[x]);
  return parent[x];
}

void unionSet(int a, int b) {
  parent[find(a)] = find(b);
}
```

---
