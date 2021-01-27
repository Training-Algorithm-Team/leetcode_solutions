// Problem: 856. Score of Parentheses - Medium
// Link: https://leetcode.com/problems/score-of-parentheses/

/* Nhận xét:
- Khi gặp dấu đóng ngoặc a, ta cần tính score của dãy ngoặc kết thúc tại a. Để tính được giá trị này, ta cần có score hiện tại trước khi gặp a.
Do đó ta lưu một biến cur chính là score của dãy tính đến thời điểm hiện tại.
- Khi gặp a, ta nhân cur với 2, trường hợp cur = 0 thì ta gán cho nó = 1.
- Sau khi gặp dấu đóng ngoặc tại a, thì score đó có thể hợp với 1 vài score trước đó để tạo nên score của dãy ngoặc ở level hiện tại. Có thể có nhiều level, và level nào 
cao nhất sẽ được sử dụng trước.
- Vậy ta dùng stack để lưu score của dãy ngoặc tại các level nhất định. Khi gặp dấu mở ngoặc b, ta sẽ push giá trị cur trước khi gặp b. Như vậy, sau khi gặp a, ta có thể
lấy giá trị top of stack, sau đó cộng với score của dãy a, để tính ra được score của level hiện tại.
- Anh thấy giải thích hơi lằng nhằng. Chú có đóng góp gì không?
*/

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int cur = 0;
        for (char &c : s) {
            if ('(' == c) {
                st.push(cur);
                cur = 0;
            } else {
                cur *= 2;
                if (0 == cur) {
                    cur = 1;
                }
                cur += st.top();
                st.pop();
            }
        }
        return cur;
    }
};
