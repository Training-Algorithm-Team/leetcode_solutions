// 1190. Reverse Substrings Between Each Pair of Parentheses - Medium
// Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

/* Nhận xét:
- Ta cần reverse string trong một cặp ngoặc, do đó ta cần lưu 1 string hiện tại đang xử lý, khi nào gặp dấu ')' thì ta reverse string đó. 
- Khi đó, string được reverse cộng với string ở phía trước cặp ngoặc lại trở thành current string. Do đó, ta cần một phương pháp để lưu lại các string phía trước
mỗi cặp ngoặc, để lấy ra sử dụng sau này. Do đó, ta sử dụng 1 stack để mỗi lần lấy ra 1 xâu ta có thể lấy xâu ngay trước cặp ngoặc hiện có để nối vào xâu hiện tại.
- Mỗi khi gặp dấu '(', ta push thêm xâu hiện tại vào stack và sẽ lấy ra để nối string sau này.
*/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string cur;
        cur.reserve(s.size());
        for (char &c : s) {
            if (c == '(') {
                st.push(cur);
                cur = "";
            } else if (c == ')') {
                reverse(cur.begin(), cur.end());
                cur = st.top() + cur;
                st.pop();
            } else {
                cur += c;
            }
        }
        return cur;
    }
};
