// 1466. Reorder Routes to Make All Paths Lead to the City Zero - Medium
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

/* Analysis:
- We start a dfs from node 0 and go through every possible edge (both forward and backward).
- If we go through a forward edge, we add 1 to the result. In order to recognize that, we need 2 adjacent list, 1 for forward edges, 1 for backward edges.
- Time complexity: O(n). A original tree has exactly (n - 1) edges => O(n + m) = O(n)
- Space complextity: O(n). Same as time complexity.
*/

class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> inNode;
    vector<vector<int>> outNode;
    int reorient = 0;
    
    void dfs(int u) {
        visited[u] = true;
        for (int &v : outNode[u]) {
            if (!visited[v]) {
                reorient++;
                dfs(v);
            }
        }
        for (int &v : inNode[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        visited.resize(n, false);
        inNode.resize(n);
        outNode.resize(n);
        for (auto &e : connections) {
            int u = e[0], v = e[1];
            outNode[u].push_back(v);
            inNode[v].push_back(u);
        }
        
        dfs(0);
        return reorient;
    }
};
