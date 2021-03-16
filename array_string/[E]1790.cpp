// 1790. Check if One String Swap Can Make Strings Equal - Easy
// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

/* Analysis:
- We track every mismatch.
- After that, we chat whether there are exactly 2 or 0 mismatch, if it's 2, these mismatches must be symmetry.
- Time complexity: O(n)
- Space complexity: O(n). We can decrase to O(1) by breaking the for loop when we see 3 mismatches.
*/
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        vector<int> diffIdx;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                diffIdx.push_back(i);
            }
        }
        int count = diffIdx.size();
        return (count == 0) || (count == 2 && (s1[diffIdx[0]] == s2[diffIdx[1]] && s1[diffIdx[1]] == s2[diffIdx[0]]));
    }
};
