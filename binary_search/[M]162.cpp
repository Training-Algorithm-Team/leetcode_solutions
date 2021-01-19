// Problem: 162. Find Peak Element - Medium
// Link: https://leetcode.com/problems/find-peak-element/

/* Nhận xét:
- Bài toán có thể diễn dịch như sau. Cho một mảng với các giá trị boolean, phần tử có giá trị true khi nums[i] > nums[i-1] và ngược lại.
=> Ta có một mảng có dạng: true true false true false true true false
- Ta cần tìm một điểm mà giá trị tại đó là true, và giá trị sau nó là false.
- Key idea của bài đó là phần tử đầu tiên luôn là true, và phần tử cuối cùng luôn là false do có 2 phần tử âm vô cùng 2 đầu dãy. Điều đó đảm bảo khi chặt nhị phân 
ta luôn có thể chọn được nửa mảng tiếp theo để duyệt. Điều kiện là: nếu mid là true, ta tìm bên phải mid; nếu mid là false, ta tìm bên trái mid.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid-1]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
