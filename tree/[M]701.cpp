// 701. Insert into a Binary Search Tree - Medium
// https://leetcode.com/problems/insert-into-a-binary-search-tree/

/* Analysis:
- We search the BST to find a place to place new val.
- If we found a null node, then we insert val here, create new node and return it.
- The caller must update the pointer to the new returned node.
- Time complexity: O(n) when BST becomes path tree.
- Space complexity: O(1)
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        } else {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};
