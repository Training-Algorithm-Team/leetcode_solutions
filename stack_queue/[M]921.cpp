// Problem: 921. Minimum Add to Make Parentheses Valid - Medium
// Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

/* Nhận xét:
- Nếu mỗi khi gặp kí tự ( ta push vào queue, và mỗi khi gặp kí tự ):
  + Nếu ( ở đầu stack, ta xóa kí tự này đi (tương đương với việc matching 1 cặp ngoặc)
  + Nếu ) ở đầu stack, ta thêm kí tự ) mới vào
- Như vậy, khi kết thúc việc duyệt, stack sẽ có dạng ‘)))((((‘ do không thể tồn tại ) phía sau (. Vậy size còn lại của stack chính là số kí tự cần thêm vào.
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(c);
                }
            }
        }
        return st.size();
    }
};
