// Problem: 636. Exclusive Time of Functions - Medium
// Link: https://leetcode.com/problems/exclusive-time-of-functions/

/* Nhận xét:
- Ta sử dụng stack để mô phỏng lại các function như trong đề bài, task nào đang nằm ở đầu queue thì đang được thực hiện và sẽ được end trước các task khác.
- Ta tin tưởng dữ liệu đầu bài sẽ đúng, nên khi gặp log mới, ta chỉ kiểm tra nếu end thì sẽ pop ra hoặc stat sẽ push vào mà không cần kiểm tra id.
- Do đó, ta chỉ cần lưu timestamp được bắt đầu được execute của 1 task. Ngoài ra trường hợp có một task chen giữa quá trình thực hiện => task hiện tại sẽ bị tạm ngưng
=> ta thêm 1 biến second vào top of stack là thời gian đã chạy được trước khi tạm ngưng của task đó.
- Khi nào một task được pop ra thì task tiếp theo sẽ được chạy lại, nên ta update lại thời gian bắt đầu lại của top of stack là timestamp + 1.
- Time complexity: O(n)
- Space complexity: O(n)
*/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> st;
        vector<int> res(n, 0);
        
        for (string &s : logs) {
            int pos1 = s.find_first_of(':');
            int pos2 = s.find_first_of(':', pos1 + 1);
            
            int id = stoi(s.substr(0, pos1));
            string action = s.substr(pos1 + 1, pos2 - pos1 - 1);
            int timestamp = stoi(s.substr(pos2 + 1));
            
            if (action == "end") {
                res[id] += timestamp - st.top().first + st.top().second + 1;
                st.pop();
                if (!st.empty()) {
                    st.top().first = timestamp + 1;   
                }
            } else {
                if (!st.empty()) {
                    st.top().second += timestamp - st.top().first;   
                }
                st.push({timestamp, 0});
            }
        }
        return res;
    }
};
