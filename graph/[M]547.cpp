// 547. Number of Provinces - Medium
// https://leetcode.com/problems/number-of-provinces/

/* Analysis:
- We need to list connected components of a graph. We can use dfs and mark visited city.
- Time complexity: O(n^2) for using adjacent matrix
- Space complexity: O(n) for boolean vector.
*/

class Solution {
private:
    vector<bool> visited;
    int n;
public:
    void dfs(vector<vector<int>> &isConnected, int u) {
        visited[u] = true;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && isConnected[u][v]) {
                dfs(isConnected, v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        visited.resize(n, false);
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(isConnected, i);
                count++;
            }
        }
        return count;
    }
};
