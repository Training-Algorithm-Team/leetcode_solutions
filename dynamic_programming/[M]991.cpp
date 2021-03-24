// 991. Broken Calculator - Medium
// https://leetcode.com/problems/broken-calculator/

/* Analysis:
- We know that, we need less increment/decrement operations on small number than with big number. So we will try to reduce the y first.
- If y < x, we just have to increment y (same as decrement x) with (x - y) ops.
- If y > x, we try to decrease y first:
  + If y is even, we divive y by 2 (1 operation)
  + If y is odd, we increment y (1 operation).
- Time complexity: O(log(y/x))
- Space complexity: O(1).
*/

class Solution {
public:
    int brokenCalc(int x, int y) {
        int count = 0;
        while (y > x) {
            count++;
            if (y % 2 == 0) {
                y /= 2;
            } else {
                y++;
            }
        }
        return count + x - y;
    }
};
