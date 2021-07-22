// https://leetcode.com/problems/minimum-knight-moves/

/* Anh thay bai nay co ve nhu co cach lam greedy, nhung anh thay no co ve phuc tap qua, ma lai can nhieu toan hoc.
- Khong biet co the ra bai nay trong phong van ko.
- Neu ra chac cung chi kip nghi den cach bfs.

*/

class Solution {
public:
    const int boardRange = 601;
    typedef pair<int, int> pii;
    const vector<pii> adjacentTiles = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    
    bool isValid(int x, int y) {
        return min(x, y) > 0 && max(x, y) < boardRange;
    }
    
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) {
            return 0;
        }
        
        vector<vector<bool>> visited(boardRange, vector<bool>(boardRange, false));
        queue<pii> q;
        int count = 0;
        x += 300;
        y += 300;
        
        visited[300][300] = true;
        q.push({300, 300});
        while (!q.empty()) {
            count++;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto [curx, cury] = q.front();
                q.pop();
                
                for (auto [dx, dy] : adjacentTiles) {
                    int nextx = curx + dx, nexty = cury + dy;
                    if (nextx == x && nexty == y) {
                        return count;
                    }
                    if (isValid(nexty, nexty) && !visited[nextx][nexty]) {
                        visited[nextx][nexty] = true;
                        q.push({nextx, nexty});
                    }
                }
            }
        }
        //Will not reach here;
        return count;
    }
};
