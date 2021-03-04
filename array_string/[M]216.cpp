// 216. Combination Sum III - Medium
// https://leetcode.com/problems/combination-sum-iii/

/* Analysis:
- For each number i of the combination, it has a range of choice from the start (previous_i + 1) and (9 + i - (k - 1))
  + We need at least k slots for k elements, so the index start from (9 - k + 1) = (9 - (k - 1))
  + If we already chose i values, so we need less slots, and the index start will be increased by i.
- We choose every elements in the possible range and call recursive function for the next number in combination.
- Time complexity: O(2^10). It will definitely be less than 2^n. This is a loose boundary
- Space complexity: O(10) = O(1) for the temporary combination.
*/

class Solution {
private:
    vector<vector<int>> res;
    
    void bt(int i, int start, int sum, vector<int> &combination, int k, int target) {
        if (i >= k || sum >= target) {
            if (i == k && sum == target) {
                res.push_back(combination);
            }
            return;
        }
        
        for (int j = start; j <= 9 + i - (k - 1); ++j) {
            combination.push_back(j);
            bt(i + 1, j + 1, sum + j, combination, k, target);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        bt(0, 1, 0, combination, k, n);
        return res;
    }
};
