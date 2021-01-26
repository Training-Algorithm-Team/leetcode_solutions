// Problem: 200. Number of Islands - Medium
// Link: https://leetcode.com/problems/number-of-islands/

/* Nhận xét:
- Duyệt toàn bộ mảng, nếu gặp phần tử 1, ta dùng phép duyệt dfs hoặc bfs từ phần tử này để tìm toàn bộ một hòn đảo hoàn chỉnh.
- Duyệt hòn đảo đến đâu thì đánh dấu đến đó (mảng visited) để tránh duyệt bị lặp
- Lặp lại cho đến khi đuyệt hết toàn bộ mảng.
*/

class Solution {
public:
    const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool valid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;   
    }
    
    void bfs(const vector<vector<char>>& grid, vector<vector<bool>> &visited, int starti, int startj) {
        queue<pair<int,int>> q;
        q.push({starti, startj});
        visited[starti][startj] = true;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < dirs.size(); ++k) {
                int nexti = i + dirs[k].first;
                int nextj = j + dirs[k].second;
                if (valid(nexti, nextj, grid.size(), grid[0].size()) && grid[nexti][nextj] == '1' && !visited[nexti][nextj]) {
                    visited[nexti][nextj] = true;
                    q.push({nexti, nextj});
                }
            }
        }
    }
  
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    count++;
                    bfs(grid, visited, i, j);   
                }
            }
        }
        return count;
    }
};
