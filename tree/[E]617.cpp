// https://leetcode.com/problems/merge-two-binary-trees/
// 617. Merge Two Binary Trees - Easy

/* Analysis:
- If a current node is null, we return the whole subtree of the other node.
- If both of them not null, we plus two of them then return a new node.
- After that, we merge the left and right subtree recursively.
- Time complexity: O(min(m, n)). m, n is the number of node of 2 trees.
- Space complexity: O(1)
*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            return root2;
        }
        
        if (root2 == nullptr) {
            return root1;
        }
        
        TreeNode* res = new TreeNode();
        res->val = root1->val + root2->val;
        
        res->left = mergeTrees(root1->left, root2->left);
        res->right = mergeTrees(root1->right, root2->right);
        
        return res;
    }
};
