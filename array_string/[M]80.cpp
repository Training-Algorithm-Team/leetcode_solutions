// Problem: 80. Remove Duplicates from Sorted Array II
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

/* Analysis:
- We maintain a pointer to keep write position and a count variable to count how many variable have the same value `cur`. We update the count variable 
based on the comparison between number i and value `cur`.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int writePointer = 1;
        int cur = nums[0], count = 1;
        int len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == cur) {
                count++;
            } else {
                count = 1;
                cur = nums[i];
            }
            if (count <= 2) {
                nums[writePointer++] = nums[i];
                len++;
            }
        }
        return len;
    }
};
