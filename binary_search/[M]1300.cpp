// Problem: 1300. Sum of Mutated Array Closest to Target - Medium
// Link: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

/* Nhận xét:
- Để tìm được, ta có thể thử tất cả các giá trị có thể từ INT_MIN -> INT_MAX, tính diff với giá trị đó, sau đó đưa ra kết luận, tuy nhiên số phép thử là quá lớn.
- Nhận thấy, giả sử x là điểm cần tìm, diff[x] - diff[x-1] < 0. Và với mọi vị trí z bên phải x đều có diff[z] - diff[z-1] >= 0. Như vây, x là điểm LỚN NHẤT mà thỏa mãn
điều kiện diff[i] - diff[i - 1] < 0. Như vậy, khi sử dụng binary search ta sẽ cho kết quả chạy về biến l.
- Time complexity: O(n * log2(INT_RANGE = 2^32)) = O(n * 32). Do độ phức tạp của hàm tính diff là O(n).
- Space complexity: O(1).
*/

class Solution {
public:
    int calDiff(const vector<int>& a, int target, int v) {
        int sum = 0;
        for (int u : a) {
            u = min(u, v);
            sum += u;
        }
        return abs(target - sum);
    }
    
    int findBestValue(vector<int>& arr, int target) {
        long l = INT_MIN, r = INT_MAX;
        while (r - l > 1) {
            long mid = l + (r - l) / 2;
            if (calDiff(arr, target, mid) >= calDiff(arr, target, mid - 1)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l;
    }
};
