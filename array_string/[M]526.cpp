// 526. Beautiful Arrangement
// https://leetcode.com/problems/beautiful-arrangement/

/* Analysis:
- We must use backtracking to list all posible cases.
- We try every not used number from 1 -> n, so we need a boolean vector to mark whether that number is used or not.
- Time complexity: O(2^n)
- Space complexity: O(n).
*/

class Solution {
public:
    int bt(vector<bool> &used, int i, int n) {
        if (i >= n + 1) {
            return 1;
        }
        
        int res = 0;
        for (int j = 1; j <= n; ++j) {
            if (!used[j] && (i % j == 0 || j % i == 0)) {
                used[j] = true;
                res += bt(used, i + 1, n);
                used[j] = false;
            }
        }
        return res;
    }
    int countArrangement(int n) {
        vector<bool> used(n + 1, false);
        return bt(used, 1, n);
    }
};
