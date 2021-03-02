// 39. Combination Sum - Medium
// https://leetcode.com/problems/combination-sum/

/* Analysis:
- For each number i, it can appear in the subset maximum j = (target / i) times. We add it to the subset j times and call recursive funtion with:
  + target = target - i * j
  + Start choose number next round from (i + 1)
 - Time complexity: O(target ^ n). For each number, it can appear in the subset at most target times.
 - Space complexity: O(n) for the temporary combination vector only.
*/

class Solution {
public:
    vector<vector<int>> res;
    
    void bt(const vector<int> &candidates, int target, vector<int> &combination, int sum, int from) {
        if (sum == target) {
            res.push_back(combination);
            return;
        }
        if (from >= candidates.size()) {
            return;
        }
        
        for (int i = from; i < candidates.size(); ++i) {
            int times = (target - sum) / candidates[i];
            for (int j = 1; j <= times; ++j) {
                combination.push_back(candidates[i]);
                bt(candidates, target, combination, sum + j * candidates[i], i + 1);
            }
            for (int j = 1; j <= times; ++j) {
                combination.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        bt(candidates, target, combination, 0, 0);
        return res;
    }
};
