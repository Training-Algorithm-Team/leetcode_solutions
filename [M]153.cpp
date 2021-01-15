// Problem: 153. Find Minimum in Rotated Sorted Array - Medium
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

/* Nhận xét:
- Bài này tương tự bài 33, anh đã đọc disscussion từ trước rồi nên ko có gì lạ :)
- Bài này xử lý l, r hơi mệt, submit sai liên tục. Chú nghĩ sao?
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (r - l > 0) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= nums[0]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return min(nums[r], nums[0]);
    }
};
