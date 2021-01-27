// Problem: 954. Array of Doubled Pairs - Medium
// Link: https://leetcode.com/problems/array-of-doubled-pairs/

/* Nhận xét:
- Ta có thể đi từ giá trị nhỏ nhất => sẽ luôn phải tìm giá trị lớn hơn của nó. Với số âm thì tìm x / 2, với số dương thì tìm x * 2.
- Với cặp giá trị này, ta giảm số lượng xuất hiện của giá trị lớn hơn đi đúng bằng số lượng của giá trị nhỏ hơn. Nếu số lượng lớn giảm xuống dưới 0 tức là không thể ghép cặp.
- Ta tiếp tục thực hiện như vậy với các giá trị tiếp theo.
- Do ta phải duyệt theo thứ tự tăng dần, ta sử dụng 1 map thay vì unordered_map.
- Time complexity: O(nlogn).
- Space complexity: O(n).
*/

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> m;
        for (int &v : arr) {
            m[v]++;
        }
        if (m[0] & 1) {
            return false;
        }
        m[0] = 0;
        for (auto it = m.begin(), e = m.end(); it != e; ++it) {
            auto [k, v] = *it;
            if (k != 0 && m[k] > 0) {
                int next;
                if (k < 0) {
                    if (k & 1 && m[k] > 0) {
                        return false;
                    }
                    next = k / 2;
                } else {
                    next = k * 2;
                }
                if (m.find(next) == m.end()) {
                    return false;
                }
                m[next] -= m[k];
                if (m[next] < 0) {
                    return false;
                }
            }
        }
        return m.rbegin()->second == 0;
    }
};
