// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

/* DFS ket hop danh dau nhung diem da di qua

*/

class Solution {
private:
    vector<vector<int>> g;
    vector<bool> visited;
    
    void dfs(int u) {
        visited[u] = true;
        
        for (auto &v : g[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        g.resize(n);
        visited.resize(n, false);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                count++;
                dfs(i);
            }
        }
        return count;
    }
};
