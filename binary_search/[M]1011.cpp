// Problem: 1011. Capacity To Ship Packages Within D Days - Medium
// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

/* Nhận xét:
- Đề bài yêu cầu xếp các thùng hàng lên thuyền theo thứ tự trong mảng weights, do đó với một capacity xác định, ta có thể xếp hàng lên một cách tham lam và đếm số ngày
cần để chuyển các thùng hàng trong O(n);
- Để tìm được capacity nhỏ nhất, ta cần thử toàn bộ các capacity từ nhỏ đến lớn, để giảm thiểu số lần thử, ta có thể dùng binary search trong trường hợp này.
- Time complexity: O(n * log(INT_MAX))
- Space complexity: O(1);
*/

class Solution {
public:
    bool canShip(vector<int>& weights, int d, int c) {
        int num = 1;
        int curw = 0;
        for (int w : weights) {
            if (w > c) {
                return false;
            }
            curw += w;
            if (curw > c) {
                num++;
                curw = w;
            }
        }
        return num <= d;
    }
    
    int shipWithinDays(vector<int>& weights, int d) {
        int l = 0, r = INT_MAX;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (canShip(weights, d, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};
