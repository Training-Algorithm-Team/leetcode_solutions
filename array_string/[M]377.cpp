// 377. Combination Sum IV - Medium
// https://leetcode.com/problems/combination-sum-iv/

/* Analysis:
- Because we just need to count the number of combinations, so we dont need to use backtracking to list all of them. I think we can use DP with memoization.
- We try every element i of the input vector, with i, we need to count all combinations with sum == (target - i) on the whole input vector (allow duplicate).
So we can use recursive approach here to calculate the large target based on small target.
- We use memoization by using a hash table to store already calculated values in order to avoid recalculating.
- Time complexity: O(target * n). Each round, we must for all n items in the vector. And each round, we can reduce the target by at least 1 => At most, target round.
Of course, it's a very loose boundary.
- Space complexity: O(target). Hash table has at most target key-value pairs.
*/

class Solution {
private:
    unordered_map<int, int> f;
public:
    int cal(const vector<int> &nums, int n) {
        if (f.find(n) != f.end()) {
            return f[n];
        }    
        
        int res = 0;
        for (const int &v : nums) {
            if (v <= n) {
                res += cal(nums, n - v);   
            }
        }
        f[n] = res;
        return res;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        f[0] = 1;
        return cal(nums, target);
        
    }
};
