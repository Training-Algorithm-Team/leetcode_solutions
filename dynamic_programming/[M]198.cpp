// 198. House Robber - Medium
// https://leetcode.com/problems/house-robber/

/* Analysis:
- We call f[i] is the maximum value we can rob for the array from 0 -> i;
- Because, at the point i, we can choose the house i or not:
  => If we choose i, f[i] = f[i-2] + a[i]. (We must skip 1 house)
  => If we not choose i, f[i] = f[i-1]. 
  => We choose max between 2 values.
- Time complexity: O(n)
- Space complexity: O(n)
  
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i-1], nums[i]);
            if (i > 1) {
                dp[i] = max(dp[i], dp[i-2] + nums[i]);
            }
        }
        return dp[n-1];
    }
};
