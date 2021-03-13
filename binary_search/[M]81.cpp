// 81. Search in Rotated Sorted Array II - Medium
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

/* Analysis:
- If target and mid are on the same side of left => we can do binary search as usually. If they are on different sides, we do it reversely.
- If left == right, we can modify the left and right until they are different. Because of that, the complexity of algorithm got increased to O(n) for the worst case.
- Time complexity: O(n) - worst case. O(log(n)) - best case.
- Space complexity: O(1).
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int l = 0, r = n - 1;
        while (r - l > 0) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target || target == nums[l] || target == nums[r]) {
                return true;
            }
            
            if (nums[mid] == nums[l]) {
                l++;
                r--;
                continue;
            }
            
            if ((nums[mid] > nums[l]) == (target > nums[l])) {
                if (target > nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else {
                if (target > nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
        }
        return nums[l] == target;
    }
};
