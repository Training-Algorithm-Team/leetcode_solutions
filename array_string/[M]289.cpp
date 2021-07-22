// https://leetcode.com/problems/game-of-life/

/* Ta chuyen cac o song thanh so am, cac o chet thi van giu nguyen la 0.
- So o song ben canh 1 o bat ki la so luong o co gia tri nho hon 0 canh o do.
- Sau khi dem xong, ta chuyen ve lai trang thai binh thuong.

*/

class Solution {
public:
    typedef pair<int, int> pii;
    const vector<pii> adj = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    
    bool isValid(vector<vector<int>> &board, int i, int j) {
        int m = board.size(), n = board[0].size();
        return min(i, j) >= 0 && i < m && j < n;
    }
    int countLiveNeighbors(vector<vector<int>> &board, int i, int j) {
        int m = board.size(), n = board[0].size();
        int count = 0;
        for (int k = 0; k < adj.size(); ++k) {
            int nexti = i + adj[k].first, nextj = j + adj[k].second;
            if (isValid(board, nexti, nextj) && board[nexti][nextj] < 0) {
                count++;
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] *= -1;
            }
        }
        
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = countLiveNeighbors(board, i, j);
                if (board[i][j] == 0) {
                    board[i][j] = count + 1;
                } else {
                    board[i][j] = -count - 1;
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 4 || board[i][j] == -3 || board[i][j] == -4) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};
