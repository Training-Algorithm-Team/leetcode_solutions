// Problem: 540. Single Element in a Sorted Array - Medium
// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

/* Nhận xét:
- Giả sử i là điểm mà phần tử chỉ có một, như vậy ta có nhận xét: Mọi số bên trái i đều đi theo cặp. Tức là nếu j < i và j chẵn, thì j là phần tử đầu tiên trong cặp số, 
tức là a[j] != a[j-1], và nếu j lẻ, tức là j là phần tử thứ 2 trong cặp số, tức là a[j] == a[j-1].
- Với tất cả các phần tử bên phải i, do đã bị điểm i làm tăng vị trí lên 1 đơn vị, nên tính chất trên bị đảo ngược.
- Như vậy, ta chỉ cần sử dụng tính chất trên để áp dụng binary search, tìm ra điểm i là điểm cuối cùng thỏa mãn tính chất ban đầu. Do đó ta sẽ sử dụng binary search, 
sử dụng biến l làm kết quả trả về.
- Time complexity: O(logn)
- Space complexity: O(1)
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if ((mid % 2 == 0 && nums[mid] != nums[mid-1]) || (mid % 2 == 1 && nums[mid] == nums[mid-1])) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};
