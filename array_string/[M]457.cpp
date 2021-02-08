// Problem: 457. Circular Array Loop - Medium
// Link: https://leetcode.com/problems/circular-array-loop/

/* Nhận xét:
- Vì số lượng phần tử của dãy là hữu hạn, mà mỗi phần tử lại trỏ đến một phần tử khác trong dãy, nên dãy sẽ có ít nhất 1 chu trình.
- Ta có thể sử dụng dfs để duyệt qua dãy, khi nào gặp một phần tử đã đi qua rồi thì dừng việc tìm kiểm và pop dần stack ra. Trong quá trình pop nếu gặp một phần tử 
trái dấu thì thay đổi res thành false. Ta chỉ trả về true khi trên đường pop stack, ta gặp một phần tử là nút của chu trình đó, ngoài ra số lượng phần tử của chu
trình > 1 và trên đương đi ko có phần tử nào trái dấu (res = true).
*/

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        stack<int> st;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int u = i;
                while (!visited[u]) {
                    st.push(u);
                    visited[u] = true;
                    u = ((u + nums[u]) % n + n) % n; // Khi ra khỏi vòng while, u sẽ là phần tử đã được gặp rồi
                }
                
                bool res = true;
                int count = 0;
                while (!st.empty()) {
                    int v = st.top();
                    st.pop();
                    ++count;
                    if (v == u && count > 1 && res) {
                        return true;
                    }
                    if ((nums[v] ^ nums[u]) < 0) { // Different sign
                        res = false;
                    }
                }
            }
        }
        return false;
    }
};
