// Problem: 145. Binary Tree Postorder Traversal - Medium
// https://leetcode.com/problems/binary-tree-postorder-traversal/

/* Nhận xét:
- Vì khi ta duyệt cây, ta duyệt từ gốc đến lá. Trong khi đó ta lại phải in giá trị theo thứ tự từ lá đến gốc, do đó khi duyệt qua một nốt, ta cần đẩy 
nó vào stack và xử dụng lại sau khi đã duyệt xong các nốt phía dưới và quay trở lại.
- Ngoài ra, khi push một nốt vào stack, ta phải lưu thêm một biến để xác định ta đã duyệt xuống các nốt con của nốt đó chưa, nếu ta thì ta duyệt tiếp 
xuống dưới, nếu rồi thì ta in giá trị của nó ra và pop ra khỏi stack.
- Chú ý là ta cần phải push giá trị vào stack theo thứ tự phải trước trái sau, để có thể được pop ra theo thứ tự trái trước phải sau.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});
        vector<int> res;
        while (!st.empty()) {
            TreeNode *u = st.top().first;
            if (!u->left && !u->right) {
                res.push_back(u->val);
                st.pop();
                continue;
            }
            if (!st.top().second) {
                st.top().second = true;
                if (u->right) {
                    st.push({u->right, false});
                }    
                if (u->left) {
                    st.push({u->left, false});
                }
            } else {
                res.push_back(u->val);
                st.pop();
            }
        }
        return res;
    }
};
