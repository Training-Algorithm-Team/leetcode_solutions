// 775. Global and Local Inversions - Medium
// https://leetcode.com/problems/global-and-local-inversions/

/* Solution 1: General approach.
- The global inversions will always be >= the local inversions. They equal only when with every number i, a[i] >= all number a[j] with (j <= i - 2).
- It means a[i] must be greater than the max element of subarray from 0 -> (i-2) => We just keep track the max value of the subarray and compare with a[i].
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
    bool isIdealPermutation(vector<int>& a) {
        int minVal = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (i >= 2) {
                minVal = max(minVal, a[i-2]);
            }
            if (a[i] < minVal) {
                return false;
            }
        }
        return true;
    }
};

/* Solution 2:
- The original array should be [0, 1, 2, ..., n-1]. We can swap only 2 adjacent elements.
- So if it's not the case, we return false right away.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
    bool isIdealPermutation(vector<int>& a) {
        int i = 0;
        while (i < a.size()) {
            if (a[i] == i) {
                i++;
                continue;
            }
            if (a[i] == i + 1 && a[i + 1] == i) {
                i += 2;
                continue;
            }
            return false;
        }
        return true;
    }
};
