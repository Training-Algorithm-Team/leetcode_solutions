// Problem: 739. Daily Temperatures - Medium
// Link: https://leetcode.com/problems/daily-temperatures/

/* Nhận xét:
- Anh đã lọc rồi nhưng có vẻ leetcode đánh tag có vấn đề nên ra bài này. Tiện tay thì anh cứ làm luôn, sry chú.
- Bài này có vẻ khá nổi tiếng, lưu một chuỗi giảm dần. Anh giải được nhưng nói thật là cũng chưa biết giải thích thế nào cho clear. Chú giải thích hộ anh nhé?
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
            int val = t[i];
            while (!st.empty()) {
                auto &[prev, idx] = st.top();
                if (prev >= val) {
                    break;
                }
                res[idx] = i - idx;
                st.pop();
            }
            st.push({val, i});
        }
        return res;
    }
};
