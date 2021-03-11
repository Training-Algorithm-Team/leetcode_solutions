// 532. K-diff Pairs in an Array - Medium
// https://leetcode.com/problems/k-diff-pairs-in-an-array/

/* Analysis:
- Because we just find unique pair, so for a value i, we just need to find out that there is at least 1 value (i - k) in the array.
- We dont need to find value (i + k) because it can cause duplicate.
- We can save them in a hash table to have the look up time O(1).
- A special case is that k == 0, => if a value appears more than 1, it will count for 1 pair. So we need to save the number of occurences in that hash table.
- Time complexity: O(n)
- Space complexity: O(n)  
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int res = 0;
        for (auto &v : nums) {
            hash[v]++;
        }
        
        for (auto &[key, val] : hash) {
            if (k == 0) {
                if (val > 1) {
                    res++;
                }
            } else {
                if (hash.find(key - k) != hash.end()) {
                    res++;
                }
            }
        }
        return res;
    }
};
