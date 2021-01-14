// Problem: 167. Two Sum II - Input array is sorted - Easy
// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

/* Nhận xét:
- Thử các giá trị của dãy, với mỗi giá trị thì dùng binary search để tìm giá trị tương ứng để tổng = target
- Ta chỉ thử các giá trị với nums[i] <= target / 2 vì mảng đã sort, những phần tử sau không thể cộng thành target
- Range search sẽ từ [i + 1, size) để tránh bị trùng với i.
- Độ phức tạp O(n * log(n))
- Có thể dùng hash map để giảm độ phức tạp xuống O(n).
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size() - 1 && numbers[i] * 2 <= target; ++i) {
            int l = i + 1, r = numbers.size();
            while (r - l > 1) {
                int mid = l + (r - l) / 2;
                if (numbers[mid] + numbers[i] <= target) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            if (numbers[l] + numbers[i] == target) {
                return {i + 1, l + 1};
            }
        }
        return {-1, -1};
    }
};
