// 1781. Sum of Beauty of All Substrings - Medium
// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

/* Analysis:
- We can build all subarrays and count frequencies for all of them => Time complexity: O(n^3);
- We can decrease the complexity by using prefix sum to quickly count frequencies.
- Time complexity: O(26 * n^2)
- Space complexity: O(26 * n)
*/

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        vector<array<int, 26>> prefix(n + 1);
        prefix[0].fill(0);
        
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i-1];
            prefix[i][s[i-1] - 'a']++;
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int minVal = INT_MAX, maxVal = 0;
                for (int k = 0; k < 26; ++k) {
                    int val = prefix[j][k] - prefix[i][k];
                    if (val != 0) {
                        minVal = min(minVal, val);
                        maxVal = max(maxVal, val);
                    }
                }
                res += maxVal - minVal;
            }
        }
        return res;
    }
};
