// 40. Combination Sum II - Medium
// https://leetcode.com/problems/combination-sum-ii/

/* Analysis
- We maintain a hash table to keep frequencies of values f[v].
- For each value, the number of it in combination varies from 0 -> f[v].
- We try all possible choices for any values in the hash table.
- Time complexity: O(2^n)
- Space complexity: O(n) for hash table.
*/

class Solution {
public:
    unordered_map<int, int> hash;
    vector<vector<int>> res;
    
    void bt(unordered_map<int, int>::iterator it, vector<int> &combination, int sum, int target) {
        if (it == hash.end() || sum >= target) {
            if (sum == target) {
                res.push_back(combination);
            }
            return;
        }
        
        bt(next(it), combination, sum, target);
        for (int i = 1; i <= it->second; ++i) {
            combination.push_back(it->first);
            bt(next(it), combination, sum + i * it->first, target);
        }
        for (int i = 0; i < it->second; ++i) {
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for (int &v : candidates) {
            hash[v]++;
        }
        vector<int> combination;
        bt(hash.begin(), combination, 0, target);
        return res;
    }
};
