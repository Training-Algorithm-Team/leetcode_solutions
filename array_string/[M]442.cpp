// 442. Find All Duplicates in an Array - Medium
// https://leetcode.com/problems/find-all-duplicates-in-an-array/

/* Solution 1: Sorting.
- We sort the array, so duplicate elements will stay closed together.
- We for thorugh the array, and check whether an element is the same with the previous element.
- Time complexity: O(nlog(n))
- Space complexity: O(1)
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        sort(a.begin(), a.end());
        
        vector<int> res;
        for (int i = 1; i < a.size(); ++i) {
            if (a[i] == a[i-1]) {
                res.push_back(a[i]);
            }
        }
        return res;
    }
};

/* Solution 2: Swapping
- Because the element are from 1 -> n, we can arrange them into n slots, item a[i] into slot (a[i] - 1) or a[i] = i + 1.
- We for throught the array, if we see an element a[i], we have 2 possible cases:
  + a[i] == i + 1, => a[i] is in the right place => ignore
  + a[i] is in wrong place => it should be moved to the slot (a[i] - 1). However, that slot already has right element, so we do not swap in order not to make infinite loop.
- 1 notice is that: after we swap, we must continue for loop with element a[i] again because it is now another element, we must test it again.
- After swapping all the array, we check the array again with 1 for loop, if we see an element not in its place, we push it to the answer.
- Time complexity: O(n).
- Space complexity: O(1).
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
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
        for (int i = 0; i < n; ++i) {
            if (a[i] != i + 1) {
                res.push_back(a[i]);
            }
        }
        return res;
    }
};
