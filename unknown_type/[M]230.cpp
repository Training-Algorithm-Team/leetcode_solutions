// Problem: 230. Kth Smallest Element in a BST
// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/* Nhận xét:
- Với một BST thì ta duyệt theo inorder traversal sẽ được một dãy tăng dần.
- Mỗi khi duyệt đến một đỉnh, ta giảm k đi 1. Khi nào giảm tới 0 thì trả về kết quả.
- Time complexity: O(max(log(n), k)), do phải mất log(n) bước để tìm phần tử nhỏ nhất, sau đó tìm k đỉnh tiếp theo. Trường hợp suy biến là O(n) khi BST bị suy biến.
- Space complexity: O(1).
*/

class Solution {
public:
    void traverse(TreeNode *u, int &k, int &res) {
        if (!u || k <= 0) {
            return;
        }
        
        traverse(u->left, k, res);
        k--;
        if (0 == k) {
            res = u->val;
            return;
        }
        traverse(u->right, k, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res;
        traverse(root, k, res);
        return res;
    }
};
