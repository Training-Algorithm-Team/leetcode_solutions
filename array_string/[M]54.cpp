// https://leetcode.com/problems/spiral-matrix/

/* Bai nay hom truoc anh voi chu code roi, lan nay anh doc qua solution cua bon no de xem cach su dung direction.
- Tuy nhien anh thay cach nay code cung hoi phuc tạp, trong mot buoi phong van ma code cach nay cung khong phu hop lam
*/

class Solution {
public:
    typedef pair<int, int> pii;
    const vector<pii> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {        
        int numRow = matrix.size(), numCol = matrix[0].size();
        vector<int> numMoves = {numCol, numRow - 1};
        vector<int> res;
        int i = 0;
        int x = 0, y = -1;
        while (numMoves[i%2] > 0) {
            for (int k = 0; k < numMoves[i%2]; k++) {
                x += dirs[i].first;
                y += dirs[i].second;
                res.push_back(matrix[x][y]);
            }
            numMoves[i%2]--;
            i = (i + 1) % 4;
        }
        return res;
    }
};
