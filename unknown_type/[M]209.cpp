// 209. Minimum Size Subarray Sum - Medium
// https://leetcode.com/problems/minimum-size-subarray-sum/

/* Analysis:
- Because of positive integers, the prefix sum will be ascending array => we can use 2 pointers on sorted array.
- We can use binary search on prefix array to produce O(nlog(n)) solution
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int curSum = 0;
        int res = INT_MAX;
        for (int j = 0; j < n; ++j) {
            curSum += nums[j];
            if (curSum < target) {
                continue;
            }
            while(curSum >= target) {
                res = min(res, j - i + 1);
                curSum -= nums[i++];
            }
        }
        return res == INT_MAX? 0 : res;
    }
};
