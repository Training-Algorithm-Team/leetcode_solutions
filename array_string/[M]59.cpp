// https://leetcode.com/problems/spiral-matrix-ii/

/* Bai nay anh thu lam cach don gian nay cho de code. Chu thay cach nao ok hon.

*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int t = 0, b = n - 1, l = 0, r = n - 1;
        
        int num = 1;
        while (n > 0) {
            for (int i = l; i <= r; ++i) {
                res[t][i] = num++;
            }
            for (int i = t + 1; i <= b; ++i) {
                res[i][r] = num++;
            }
            for (int i = r - 1; i >= l; --i) {
                res[b][i] = num++;
            }
            for (int i = b - 1; i > t; --i) {
                res[i][l] = num++;
            }
            t++; l++;
            b--; r--;
            n -= 2;
        }
        return res;
    }
};
