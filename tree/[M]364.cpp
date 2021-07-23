// https://leetcode.com/problems/nested-list-weight-sum-ii/

/* Truoc het ta tinh do sau cua cua cay.
- Sau do ta dung DFS de duyet qua toan bo cac not va tinh tong.
- Tuy nhien, bon no co vai cach hay hon nhu luu toan bo tong cua cac level ra 1 mang, de chi phai duyet DFS 1 lan, hoac la tinh tong den level hien tai, 
neu con level tiep thi lai don xuong tiep, cac so o level cao duoc cong nhieu lan.

*/

class Solution {
public:
    int calDepth(NestedInteger &ni) {
        if (ni.isInteger()) {
            return 1;
        }
        int level = 0;
        auto nl = ni.getList();
        for (auto it = nl.begin(); it != nl.end(); it++) {
            level = max(level, calDepth(*it));
        }
        return 1 + level;
    }
    int calSum(NestedInteger &ni, int curDepth, int maxDepth) {
        if (ni.isInteger()) {
            return ni.getInteger() * (maxDepth - curDepth + 1);
        }
        auto nl = ni.getList();
        int curSum = 0;
        for (auto it = nl.begin(); it != nl.end(); it++) {
            curSum += calSum(*it, curDepth + 1, maxDepth);
        }
        return curSum;
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = 0;
        for (auto it = nestedList.begin(); it != nestedList.end(); it++) {
            depth = max(depth, calDepth(*it));
        }
        int sum = 0;
        for (auto it = nestedList.begin(); it != nestedList.end(); it++) {
            sum += calSum(*it, 1, depth);
        }
        return sum;
    }
};
