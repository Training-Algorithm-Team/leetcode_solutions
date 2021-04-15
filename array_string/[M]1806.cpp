// 1806. Minimum Number of Operations to Reinitialize a Permutation - Medium
// https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/

/* Analysis:
- I cannot prove but I think that when an index returns to its first value, the permutation will be the same.
- So I simulate an index only, transform it each round until it is the same as the original.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
    int reinitializePermutation(int n) {
        int i = 1;
        int start = 1;
        int count = 0;
        do {
            if (i < n / 2) {
                i = i * 2;
            } else {
                i = (i - n / 2) * 2 + 1;
            }
            count++;
        } while (i != start);
        return count;
    }
};
