// Problem: 1249. Minimum Remove to Make Valid Parentheses - Medium
// Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

/* Nhận xét:
- Nhận thấy, nếu các dấu ( và ) match với nhau thì đoạn phía trong nó là valid. Sau khi match toàn bộ các ( ) thì những dấu không valid còn lại sẽ có dạng )))(((.
- Xóa những phần tử này đi ta sẽ có được string ta cần. Ta có thể dùng stack để matching các dấu với nhau.
- Stack này cần lưu thêm index của dấu để có thể xóa đi sau khi duyệt xong.
- Time complexity: O(n)
- Space complexity: O(n) 
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<pair<char, int>> st;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if ('(' == c) {
                st.push({c, i});
            } else if (')' == c) {
                if (!st.empty() && st.top().first == '(') {
                    st.pop();
                } else {
                    st.push({c, i});
                }
            }
        }
        
        stack<int> toRemove;
        while (!st.empty()) {
            toRemove.push(st.top().second);
            st.pop();
        }
        string res;
        res.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (!toRemove.empty() && i == toRemove.top()) {
                toRemove.pop();
            } else {
                res += s[i];
            }
        }
        return res;
    }
};
