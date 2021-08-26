// 55. Jump Game
// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIdx = 0;
        for (int i = 0; i < n && i <= maxIdx; i++) {
            maxIdx = max(maxIdx, nums[i] + i);
        }
        return maxIdx >= n - 1;
    }
};
