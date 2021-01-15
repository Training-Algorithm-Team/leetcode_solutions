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
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i+1, j+1};
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {-1,-1};
    }
};
