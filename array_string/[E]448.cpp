// 448. Find All Numbers Disappeared in an Array - Easy
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

/* Analysis:
- Same as problem 442.
- After swapping all elements, if we a position that does not have right element for it (a[i] != i + 1) => (i + 1) does not exist in the array.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        int n = a.size();
        int i = 0;
        while (i < n) {
            int nextPos = a[i] - 1;
            if (a[i] != i + 1 && a[nextPos] != nextPos + 1) {
                swap(a[i], a[nextPos]);
            } else {
                ++i;
            }
        }
        
        vector<int> res;
        for (i = 0; i < n; ++i) {
            if (a[i] != i + 1) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
