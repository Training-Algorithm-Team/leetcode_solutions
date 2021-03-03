// 695. Max Area of Island - Medium
// https://leetcode.com/problems/max-area-of-island/

/* Analysis:
- We search every grid (m x n), if we see a grid that is not visited and is a land, we start a bfs from here. 
- We check adjacent grids of 4 directions, if we meed another `not visited + land`, we add it to the queue to visit later and +1 to the area.
- For the visited grid, we mark it 2 (visited + land) to distinguish with 1 (not visited + land)
- Time complexity: O(m x n). The significant expression here is `grid[nexti][nextj] == 1` and is called at most a constant times.
- Space complexity: O(1)
*/

class Solution {
public:
    typedef pair<int, int> pii;
    const vector<pii> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int m, n;
    
    bool valid(int i , int j) {
        return min(i, j) >= 0 && i < m && j < n;
    }
    int bfs(vector<vector<int>> &grid, int &row, int &col) {
        int i = row, j = col;
        queue<pii> q;
        q.push({i, j});
        int area = 1;
        grid[i][j] = 2;
        
        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            
            for (int k = 0; k < dirs.size(); ++k) {
                int nexti = i + dirs[k].first;
                int nextj = j + dirs[k].second;
                if (valid(nexti, nextj) && grid[nexti][nextj] == 1) {
                    area++;
                    grid[nexti][nextj] = 2;
                    q.push({nexti, nextj});
                }
            }
        }
        return area;        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }   
        m = grid.size(), n = grid[0].size();
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    res = max(res, bfs(grid, i, j));
                }
            }
        }
        return res;
    }
};
