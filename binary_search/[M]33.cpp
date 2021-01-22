// Problem: 33. Search in Rotated Sorted Array
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

/* Nhận xét:
- Sau khi vẽ và thử các trường hợp có thể, ta thấy bài này có thể sử dụng binary search, key point là phải điều chỉnh biên l, r hợp lý trong từng trường hợp.
- Trường hợp này tôi vẽ ra giấy để tưởng tượng các trường hợp có thể nên hơi khó giải thích ở đây. Bạn có cách giải thích nào tốt hơn không?
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                if (target >= nums[l] || nums[mid] < nums[l]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target < nums[l] || nums[l] < nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        if (nums[l] == target) {
            return l;
        } else if (nums[r] == target) {
            return r;
        } else {
            return -1;
        }
    }
};
