// 238. Product of Array Except Self - Medium
// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> res(n, 1);
        for (int i = 1, cur = 1; i < n; ++i) {
            cur *= nums[i-1];
            res[i] *= cur;
        }
        for (int i = n - 2, cur = 1; i >= 0; --i) {
            cur *= nums[i+1];
            res[i] *= cur;
        }
        return res;
    }
};
