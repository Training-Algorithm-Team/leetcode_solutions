// https://leetcode.com/problems/nested-list-weight-sum/

/* Bai nay thi de hon, ta chi can luu level hien tai thi chay den dau co the tinh ngay ket qua den do.

*/

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList, int level = 1) {
        int sum = 0;
        for (auto ni : nestedList) {
            if (ni.isInteger()) {
                sum += ni.getInteger() * level;
            } else {
                sum += depthSum(ni.getList(), level + 1);
            }
        }
        return sum;
    }
};
