// 1177. Can Make Palindrome from Substring - Medium
// https://leetcode.com/problems/can-make-palindrome-from-substring/

/* Solution:
- In order to determine whether we can make the palindrom, we need to count the number of each characters in the query string. We can calculate them using
perfix sum technique with every 26 characters.
- After that, for each query, a substring can be made palindrome when k is greater or equal to number of character with odd occurences.
- Time complexity: O(26n)
- Space complexity: O(26n)
*/

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>> freq(n + 1, vector<int>(26, 0));
        for (int i = 1; i <= n; ++i) {
            freq[i][s[i-1] - 'a']++;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                freq[i][j] += freq[i-1][j];
            }
        }
        
        vector<bool> res;
        for (vector<int> &q : queries) {
            int left = q[0], right = q[1], k = q[2];
            
            int count = 0;
            for (int i = 0; i < 26; ++i) {
                if ((freq[right + 1][i] - freq[left][i]) & 1) {
                    count++;
                }
            }
            if (k >= count / 2) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};
