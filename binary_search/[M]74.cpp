// https://leetcode.com/problems/search-a-2d-matrix/

/* Analysis:
- We can treat the 2D matrix as a sorted list and do binary search as regular.

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (r - l >= 0) {
            int mid = l + (r - l) / 2;
            int val = matrix[mid/n][mid%n];
            if (val == target) {
                return true;
            } else if (val > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};
