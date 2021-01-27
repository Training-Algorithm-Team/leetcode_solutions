// Problem: 1642. Furthest Building You Can Reach - Medium
// Link: https://leetcode.com/problems/furthest-building-you-can-reach/

/* Nhận xét:
- Bài này tạm thời anh chưa nghĩ ra cách tốt hơn, nên anh dùng cách binary search này, độ phức tạp hơi cao 1 chút.
- Nhận thấy với một đoạn cố định, ta ưu tiên dùng ladders để leo những tòa nhà có chênh lệch cao nhất trước, sau đó xem dùng bricks thì có thể leo nốt những tòa còn lại
hay không. Như vậy với một đoạn cố định, ta có thể chuyển thành mảng chênh lệch giữa tòa trước và tòa sau, sau đó sort theo thứ tự giảm dần độ chênh lệch và xử lý.
- Giả sử l là điểm xa nhất ta có thể tới, thì các điểm trước đó ta đều có thể tới, và các điểm sau đó ta đều không thể tới. Vậy ta có thể dùng binary search để
giảm số lượng phép thử.
- Time complexity: O(log(n) * nlog(n)). log(n) vòng binary search, mối vòng ta cần sort lại với độ phức tạp nlog(n)
- Space complexity: O(n) cho mảng diff.
*/

class Solution {
public:
    bool canReach(vector<int> diff, int bricks, int ladders, int end) {
        sort(diff.begin(), diff.begin() + end, greater<int>());
        for (int &d : diff) {
            if (d <= 0) {
                return true;
            }
            if (ladders > 0) {
                ladders--;
            }
            else {
                bricks -= d;
                if (bricks < 0) {
                    return false;
                }
            }
        }
        return true;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        vector<int> diff(n, 0);
        for (int i = 1; i < n; ++i) {
            diff[i] = heights[i] - heights[i-1];
        }
        
        int l = 0, r = n;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (canReach(diff, bricks, ladders, mid + 1)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
