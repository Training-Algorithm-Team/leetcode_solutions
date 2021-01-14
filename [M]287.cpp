// Problem: 287. Find the Duplicate Number - Medium
// Link: https://leetcode.com/problems/find-the-duplicate-number/

/* Nhận xét:
- Ta có thể lưu một vector<bool> để xử lý với độ phức tạp O(n) nhưng có space complexity là O(n)
- Đề bài yêu cầu không dùng thêm bộ nhớ, không sửa đổi mảng ban đầu.
- Độ dài mảng ban đầu là hữu hạn, ta có thể chặt đôi, với mỗi lần, ta kiểm tra xem số lượng phần tử <= mid. Nếu số lượng này <= mid => Ta cần tìm trong khoảng [mid + 1, r]. 
- Ngược lại ta tìm trong khoảng [l, mid]
*/

class Solution {
public:
    int countLess(const vector<int>& nums, int x) {
        int count = 0;
        for (int v : nums) {
            if (v <= x) {
                ++count;
            }
        }
        return count;
    }
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        while (r - l > 0) {
            int mid = l + (r - l) / 2;
            if (countLess(nums, mid) <= mid) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
