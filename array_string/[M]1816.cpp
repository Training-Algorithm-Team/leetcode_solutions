// 1816. Truncate Sentence - Easy
// https://leetcode.com/problems/house-robber/

/* Analysis:
- We find for space character for k times.
- After that, we return the substring from 0 to the position we found.
- Time complexity: O(n);
- Space complexity: O(1);
*/

class Solution {
public:
    string truncateSentence(string s, int k) {
        int pos = 0;
        for (int i = 0; i < k; ++i) {
            pos = s.find(" ", pos + 1);
        }
        return s.substr(0, pos);
    }
};
