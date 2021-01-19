// Problem: 367. Valid Perfect Square - Easy
// Link: https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 1, r = num;
        while (r - l > 1) {
            long mid = l + (r - l) / 2;
            if (mid * mid <= num) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l * l == num;
    }
};
