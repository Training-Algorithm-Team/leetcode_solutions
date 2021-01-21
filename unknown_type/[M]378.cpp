// Problem: 378. Kth Smallest Element in a Sorted Matrix - Medium
// Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

/* Nhận xét:
- Bài này anh chịu rồi :))
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> a;
        for (auto &vt : matrix) {
            for (auto &val : vt) {
                a.push_back(val);
            }
        }
        sort(a.begin(), a.end());
        return a[k-1];
    }
};
