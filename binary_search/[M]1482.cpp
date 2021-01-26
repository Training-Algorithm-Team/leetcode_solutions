// Problem: 1482. Minimum Number of Days to Make m Bouquets - Medium
// Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

/* Nhận xét:
- Chỉ tạo được 1 bó hoa từ các bông hoa kề nhau => Với 1 ngày cụ thể, ta có thể sử dụng tham lam để tạo các bó hoa với độ phức tạp O(n).
- Giả sử d là đáp áp thì các ngày trước đó sẽ ko tạo đủ m bó hoa, và các ngày sau đó thì sẽ tạo được => Ta có thể nghĩ đến binary search.
- Vì là tìm số ngày nhỏ nhất => Ta đưa kết quả về biến r.
- Time complexity: o(log(2 ^ 31) * n)
- Space complexity: O(1).
*/

class Solution {
public:
    bool canMake(const vector<int>& bloomDay, int m, int k, int d) {
        int count = 0, adj = 0;
        for (auto &b : bloomDay) {
            if (b <= d) {
                if (++adj >= k) {
                    count++;
                    adj = 0;
                }
            } else {
                adj = 0;
            }
        }
        return count >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n) {
            return -1;
        }
        int l = 0, r = INT_MAX;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (canMake(bloomDay, m, k, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r == INT_MAX ? -1 : r;
    }
};
