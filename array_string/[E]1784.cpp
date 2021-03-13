// 1784. Check if Binary String Has at Most One Segment of Ones - Medium
// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/

/* Analysis:
- We count all segments of '1' and return true if it's less that 1.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
    bool checkOnesSegment(string s) {
        char prev = '0';
        int count = 0;
        for (char &c : s) {
            if (c == '1' && c != prev) {
                count++;
            }
            prev = c;
        }
        return count <= 1;
    }
};
