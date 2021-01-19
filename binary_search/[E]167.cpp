// Problem: 167. Two Sum II - Input array is sorted - Easy
// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

/* Nhận xét:
- Thử các giá trị của dãy, với mỗi giá trị thì dùng binary search để tìm giá trị tương ứng để tổng = target
- Ta chỉ thử các giá trị với nums[i] <= target / 2 vì mảng đã sort, những phần tử sau không thể cộng thành target
- Range search sẽ từ [i + 1, size) để tránh bị trùng với i.
- Độ phức tạp O(n * log(n))
- Có thể dùng hash map để giảm độ phức tạp xuống O(n).

- Ngoài ra, có thể có thêm 1 cách khác, sử dụng kĩ thuật sliding windows - 2 pointers để xử lý:
    + Ban đầu, ta lấy tổng của phần tử đầu và phần tử cuối của dãy rồi so sánh với target, gọi là i và j tương ứng với đầu và cuối.
    + Ta có nhận xét nếu tổng này > target => Mọi phần tử sau i nếu cộng với j thì đều khiền cho tổng tăng lên => không thể có sum = target. Do đó ta chỉ cần cho j--
    để khiến tổng tạo ra có khả năng = target và sau đó thử tiếp.
    + Tương tự với trường hợp < target => Ta cần cho i++.
*/

// C1: Binary search.
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

// C2: 2 pointers
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
