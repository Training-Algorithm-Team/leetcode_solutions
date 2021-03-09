// 1786. Number of Restricted Paths From First to Last Node - Medium
// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/

/* Solution 1: DFS + Memoization.
- First, we must calculate the distance to last node of every node and save them to vector "d". We can do it by using Bellman-Ford algorithm + queue.
- After that, we use a vector "dp" in which dp[i] = number of restricted paths from i => lastNode. dp[lastNode] = 1.
- For a particular restricted path like this: i -> j -> lastNode, all paths from j-> lastNode can be counted for number of paths from i-> lastNode.
=> dp[i] = dp[i] + dp[j], for every j adjacent to i.
- So we can start an dfs from first node. For every adjacent node i of firstNode, we start another dfs from i to calculate dp[i]. If we reach a node that has 
dp[j] calculated, we can return immediately (dp[lastNode] = 1). Time complexity of this action will be O(n) because every node will be calculated once and only one.
- Time complexity: n = number of nodes, m = number of edges.
  + Worst case: O(n * m) - for Bellman-Ford on full graph. It's a very loose boundary.
  + Average case: O(m * log(m + n)) as Mr. Quynh said :))
- Space complexity: O(n + m) for adjacent list and dp table.
*/

class Solution {
public:
  const int mod = 1e9 + 7;
  typedef pair<int, int> pii;
    vector<int> d;
    vector<vector<pii>> adj;
    vector<int> dp;
    
    void dfs(int u) {
      int count = 0;
      dp[u] = 0;
      for (auto &[v, w] : adj[u]) {
        if (d[v] < d[u]) {
          if (dp[v] == -1) {
            dfs(v); 
          }
          count += dp[v];
          count %= mod;
        }
      }
      dp[u] = count;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
      d.resize(n+1, INT_MAX);
      d[n] = 0;
      adj.resize(n+1);
      dp.resize(n+1, -1);
      dp[n] = 1;

      for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
      }
      
      queue<int> q;
      q.push(n);
      
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (auto &[v, w] : adj[u]) {
          if (d[v] > d[u] + w) {
            d[v] = d[u] + w;
            q.push(v);
          }
        }
      }
      
      dfs(1);
      return dp[1];
    }
};

/* Solution 2: DP tabulation.
- Instead of counting dp[j] on demand, we can go from bottom up. It means we must update nodes that are near the lastNode first (according to distance).
- So we sort nodes based on their distance and build the dp table in ascending order.
- Time complexity: Same as before. The sorting step does not increase the complexity.
- Space complexity: Same.
*/

class Solution {
public:
  const int mod = 1e9 + 7;
  typedef pair<int, int> pii;
    vector<int> d;
    vector<vector<pii>> adj;
    vector<int> dp;
    
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
      d.resize(n+1, INT_MAX);
      d[n] = 0;
      adj.resize(n+1);
      dp.resize(n+1, 0);
      dp[n] = 1;
      
      vector<int> idx(n + 1);
      iota(idx.begin(), idx.end(), 0);
        
      for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
      }
      
      queue<int> q;
      q.push(n);
      
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (auto &[v, w] : adj[u]) {
          if (d[v] > d[u] + w) {
            d[v] = d[u] + w;
            q.push(v);
          }
        }
      }
      
      sort(idx.begin(), idx.end(), [&](const int &a, const int &b) {
        return d[a] < d[b]; 
      });
      
      for (int i = 0; i < n; ++i) {
        int u = idx[i];
        for (auto &[v, w] : adj[u]) {
          if (d[v] > d[u]) {
             dp[v] += dp[u];
            dp[v] %= mod;
          }
        }
      }
      
      return dp[1];
    }
};
