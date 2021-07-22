// https://leetcode.com/problems/word-search/

/* Ta dung dfs tu moi diem trong ma tran.

*/

class Solution {
public:
    typedef pair<int, int> pii;
    const vector<pii> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isValid(vector<vector<char>> &board, int x, int y) {
        return min(x, y) >= 0 && x < board.size() && y < board[0].size();
    }
    
    bool dfs(vector<vector<char>> &board, int x, int y, string &word, int i, vector<vector<bool>> &visited) {
        if (i == word.size() - 1 && board[x][y] == word[i]) {
            return true;
        }
        if (board[x][y] != word[i]) {
            return false;
        }
        visited[x][y] = true;
        for (int k = 0; k < dirs.size(); ++k) {
            int nextx = x + dirs[k].first;
            int nexty = y + dirs[k].second;
            
            if (isValid(board, nextx, nexty) && !visited[nextx][nexty] && dfs(board, nextx, nexty, word, i+1, visited)) {
                return true;
            }
        }
        visited[x][y] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, i, j, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
