// 90. Subsets II - Medium
// https://leetcode.com/problems/subsets-ii/

/* Solution:
- First, we maintain a hash table to count the frequency of each value f[v]. For each value, we have (f[v] + 1) choices to add that value into subset.
- We use backtracking with that hash table, for each value, we use an iterator to indicate.
- Time complexity: O(m ^ (n/m)) with m is average frequency of a value. ==> Chú check hộ anh cái này cái.
- Space complexity: O(n) for hash table.
*/

class Solution {
private:
    vector<vector<int>> res;
    unordered_map<int, int> noDup;
public:
    void bt(unordered_map<int, int>::iterator it, vector<int> &subset) {
        if (it == noDup.end()) {
            res.push_back(subset);
            return;
        }
        
        auto &[k, v] = *it;
        bt(next(it), subset);
        for (int j = 0; j < v; ++j) {
            subset.push_back(k);
            bt(next(it), subset);
        }
        for (int j = 0; j < v; ++j) {
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for (int v : nums) {
            noDup[v]++;
        }
        
        vector<int> subset;
        bt(noDup.begin(), subset);
        return res;
    }
};
