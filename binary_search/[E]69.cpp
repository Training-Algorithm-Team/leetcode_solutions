// Problem: 69. Sqrt(x) - Easy
// Link: https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l <= r) {
            // cout << "l = " << l << " r = " << r << endl;
            long mid = l + (r - l) / 2;
            long p = mid * mid;
            if (p > x) {
                r = mid - 1;
            } else if (p < x) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return r;
    }
};
