// Problem: 1237. Find Positive Integer Solution for a Given Equation - Medium
// Link: https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/

/* Nhận xét:
- Với mỗi giá trị của x, ta cần thử tất cả giá trị của y để kiểm tra f(x, y) == z
- Vì nếu y2 > y1 <=> f(x, y2) > f(x, y1), như vậy ta có thể sử dụng binary search trên trục y để tìm ra giá trị của y.
- Time complexity: O(mlog(n)).
- Space complexity: O(1).
*/

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        for (int i = 1; i <= 1000; i++) {
            int l = 1, r = 1001;
            while (r - l > 1) {
                int mid = l + (r - l) / 2;
                if (customfunction.f(i, mid) <= z) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            if (customfunction.f(i, l) == z) {
                res.push_back({i, l});
            }
        }
        return res;
    }
};
