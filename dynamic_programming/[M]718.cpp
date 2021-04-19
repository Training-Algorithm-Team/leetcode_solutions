// 718. Maximum Length of Repeated Subarray - Medium
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

/* Analysis
- Use DP
- Time complexity: O(m * n)
- Space complexity: O(m * n)
*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            if (nums1[i] == nums2[0]) {
                dp[i][0] = 1;
                res = 1;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (nums1[0] == nums2[j]) {
                dp[0][j] = 1;
                res = 1;
            }
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};
