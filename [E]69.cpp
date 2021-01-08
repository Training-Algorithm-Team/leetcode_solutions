// Problem: 69. Sqrt(x) - Easy
// Link: https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        // cout << (int)sqrt(INT_MAX) << endl;
        // I must cout to find the max of range first, before searching.
        int l = 0, r = 46340;
        while (l <= r) {
            int mid = (l + r) / 2;
            int p = mid * mid;
            if (p < x) l = mid + 1;
            else if (p > x) r = mid - 1;
            else return mid;
        }
        return r;
    }
};
