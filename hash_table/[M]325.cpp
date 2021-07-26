// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefix;
        prefix[0] = -1;
        
        int sum = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            auto it = prefix.find(sum - k);
            if (it != prefix.end()) {
                res = max(res, i - it->second);
            }
            if (prefix.find(sum) == prefix.end()) {
                prefix[sum] = i;
            }
        }
        return res;
    }
};
