// Problem: 128. Longest Consecutive Sequence - Hard
// Link: https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> hash(nums.begin(), nums.end());
        int res = 0;
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            int u = *it;
            int v = u - 1;
            int cur = 1;
            while (hash.count(v)) {
                cur++;
                hash.erase(v--);
            }
            v = u + 1;
            while (hash.count(v)) {
                cur++;
                hash.erase(v++);
            }
            res = max(res, cur);
        }
        return res;
    }
};
