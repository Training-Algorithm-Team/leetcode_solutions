// https://leetcode.com/problems/count-complete-tree-nodes/

/* Analysis:
- If height left = height right => left is full BT, right is not => sum = count left + curNode + countRight = 2^h + countRight
- Same with the right.
*/

class Solution {
public:
    int height(TreeNode *u) {
        return u == nullptr? -1 : 1 + height(u->left);
    }
    int countNodes(TreeNode* root) {
        int h = height(root);
        if (h < 0) {
            return 0;
        }
        if (height(root->right) == h-1) {
            return (1 << h) + countNodes(root->right);
        } else {
            return (1 << (h-1)) + countNodes(root->left);
        }
    }
};
