// Problem: 278. First Bad Version - Easy
// Link: https://leetcode.com/problems/first-bad-version/

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};
