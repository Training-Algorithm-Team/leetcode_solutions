// https://leetcode.com/problems/two-sum-less-than-k/

/* Ta dung set de track nhung phan tu da di qua, tai moi phan tu thi tim lai trong set => Time complextiy: O(n(logn))
- Ta cung co the sort lai roi dung 2 pointers tren do

*/

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> s;
        
        int res = -1;
        for (int i = 0; i < n; i++) {
            auto it = s.lower_bound(k - nums[i]);
            if (it != s.begin()) {
                res = max(res, *prev(it) + nums[i]);
            }
            s.insert(nums[i]);
        }
        return res;
    }
};
