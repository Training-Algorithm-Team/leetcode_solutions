// 78. Subsets - Medium
// https://leetcode.com/problems/subsets/

/* Solution:
- 1 subset can be defined by whether each element is selected. We maintain a boolean vector for that purpose.
- We use backtracking to generate the boolean vector, at each position i, we have 2 possible choice for it, use it (true) or not use it (false)
- Time complexity: O(2 ^ n)
- Space complexity: O(n) for boolean vector. The result has size 2^n but it's not counted for complexity.
*/

class Solution {
private:
    vector<bool> used;
    int n;
    vector<vector<int>> res;
public:
    void bt(const vector<int>& nums, int i) {
        if (i == n) {
            vector<int> subset;
            for (int j = 0; j < n; ++j) {
                if (used[j]) {
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
            return;
        }
        used[i] = true;
        bt(nums, i + 1);
        used[i] = false;
        bt(nums, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        used.resize(n, false);
        bt(nums, 0);
        return res;
    }
};
