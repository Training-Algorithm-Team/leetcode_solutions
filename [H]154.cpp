// Problem: 154. Find Minimum in Rotated Sorted Array II - Hard
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

/* Nhận xét:
- Xử lý như bình thường:
   + Nếu mid > r => (mid, r] là đoạn bất thường, điểm nhỏ nhất nằm ở đây. Xét tiếp đoạn [l = mid + 1, r]
   + Nếu ngược lại, => [l, mid] là đoạn bất thường. Xét tiếp đoạn [l, r = mid]. Chú ý ở đây phải là r = mid, vì mid có thể = r => mid cũng có thể là điểm nhỏ nhất
   => Gán r = mid để không bỏ sót điểm mid.
   + Ta đặt điều kiện (l - r) > 0 => khi kết thúc thì l = r => return l hay r đều ok.
- Trường hợp đặc biệt: l = mid = r => không thể biết bỏ đoạn nào => bắt buộc phải xét tiếp cả 2, ta chỉnh lại 2 biên l++ và r--.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (r - l > 0) {
            int mid = l + (r - l) / 2;
            if (nums[l] < nums[r]) {
                return nums[l];
            } else if (nums[l] == nums[r] && nums[l] == nums[mid]) {
                l++, r--;
                continue;
            }
            
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};
