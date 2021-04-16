// 152. Maximum Product Subarray - Medium
// https://leetcode.com/problems/maximum-product-subarray/

/* Analysis:
- We define:
  + fPos[i] = max positive product of subarray that ends at i
  + fNeg[i] = min negative product of subarray that ends at i
- We depends on the sign of number i to determine the value of fPos and fNeg.
- The final result will be max of all fPos (can be 0);
- Time complexity: O(n)
- Space complexity: O(1)

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
            
        }
        vector<int> fPos(n, 0);
        vector<int> fNeg(n, 0);
        
        fPos[0] = max(0, nums[0]);
        fNeg[0] = min(0, nums[0]);
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] >= 0) {
                fPos[i] = max(nums[i], fPos[i-1] * nums[i]);
                fNeg[i] = min(0, fNeg[i-1] * nums[i]); 
            } else {
                fPos[i] = max(0, nums[i] * fNeg[i-1]);
                fNeg[i] = min(nums[i], fPos[i-1] * nums[i]);
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, fPos[i]);
        }
        return res;
    }
};
