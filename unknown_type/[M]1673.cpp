// Problem: 1673. Find the Most Competitive Subsequence - Medium
// Link: https://leetcode.com/problems/find-the-most-competitive-subsequence/

/* Nhận xét:
- Với một subsequence s với độ dài k, giả sử ta chọn vị trí pos, như vậy các khả năng có thể chọn được cho pos là các nums[i] nằm trong khoảng prev < nums[i] <= n - k + pos.
- Trong khoảng này, ta cần tìm số nhỏ nhất có thể, nếu có 2 số nhỏ nhất thì ta chọn số đầu tiền xuất hiện để tăng cơ hội chọn được thêm các số nhỏ khác.
Điều này đưa ta đến với ý tưởng sử dụng heap để chọn số nhỏ nhất tại mỗi thời điểm.
- Time complexity: O(n * log(n))
- Space complexity: O(n)
- Bài này anh không nghĩ ra được phương án tốt hơn. Chú thấy thế nào?
*/

class Solution {
public:
    typedef pair<int, int> pii;
    
    class Comp {
    public:
        bool operator()(const pii &a, const pii &b) {
            return a.first > b.first || (a.first == b.first && a.second > b.second);
        }
    };
    
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pii, vector<pii>, Comp> heap;
        vector<int> res(k);
        int prev = -1;
        int pos = 0;
        for (int i = 0; i < n && pos < k; ++i) {
            int upBound = n - k + pos;
            
            heap.push({nums[i], i});
            if (i == upBound) {
                auto value_idx = heap.top();
                while (value_idx.second <= prev) {
                    heap.pop();
                    value_idx = heap.top();
                }
                heap.pop();
                res[pos++] = value_idx.first;
                prev = value_idx.second;
            }
            
        }
        
        return res;
    }
};
