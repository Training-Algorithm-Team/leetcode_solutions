// https://leetcode.com/problems/rotting-oranges/

/* Ta day cac qua hong vao trong queue, sau do bfs tu queue nay

*/

class Solution {
public:
    typedef pair<int, int> pii;
    const vector<pii> dirs = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    
    bool isValid(int m, int n, int x, int y) {
        return min(x, y) >= 0 && x < m && y < n;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int total = 0;
        queue<pii> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    total++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        int minutes = 0;
        while (!q.empty()) {
            int s = q.size();
            bool next = false;
            for (int k = 0; k < s; k++) {
                auto [x, y] = q.front();
                q.pop();
                
                for (int d = 0; d < dirs.size(); ++d) {
                    int nextx = x + dirs[d].first, nexty = y + dirs[d].second;
                    if (isValid(m, n, nextx, nexty) && grid[nextx][nexty] == 1) {
                        next = true;
                        total--;
                        grid[nextx][nexty] = 2;
                        q.push({nextx, nexty});
                    }
                }
            }
            if (next) {
                minutes++;
            }
        }
        return total > 0? -1 : minutes;
    }
};
