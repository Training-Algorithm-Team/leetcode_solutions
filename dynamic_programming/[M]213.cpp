// 213. House Robber II - Medium
// https://leetcode.com/problems/house-robber-ii/

/* Analysis:
- Same as House Robber problem, however, the house 0 and (n - 1) now are adjacent, so we cannot calculate to f[n-1].
- Instead, the solution can come from robbing from 2 different segment;
  + 0 -> (n - 2)
  + 1 -> (n - 1)
- The way to choose will fit perfectly on 1 segment or both. So we just need to get max of them.
- Time complexity: O(n)
- Space complexity: O(1)
*/ 

class Solution {
public:
    int robSegment(const vector<int> &a, int start, int end) {
        int f1 = a[start];
        int f2 = max(a[start], a[start+1]);
        
        for (int i = start + 2; i <= end; ++i) {
            int cur = max(f1 + a[i], f2);
            f1 = f2;
            f2 = cur;
        }
        return f2;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        }
        
        return max(robSegment(nums, 0, n-2), robSegment(nums, 1, n - 1));
    }
};
