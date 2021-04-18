// 623. Add One Row to Tree - Medium
// https://leetcode.com/problems/add-one-row-to-tree/

/* Analysis:
- We go down the tree to the target depth and create new node as required.
- The worst case we must traverse through the whole tree.
- Time complexity: O(n). n = number of nodes.
- Space complexity: O(1)
*/

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth, int curDepth = 1) {
        if (curDepth == depth) {
            // depth = 1 only
            TreeNode *newRoot = new TreeNode(val, root, nullptr);
            root = newRoot;
        } else if (curDepth == depth - 1) {
            TreeNode *l = new TreeNode(val, root->left, nullptr);
            root->left = l;
            
            TreeNode *r = new TreeNode(val, nullptr, root->right);
            root->right = r;
        } else {
            if (root->left) {
                addOneRow(root->left, val, depth, curDepth + 1);    
            }
            if (root->right) {
                addOneRow(root->right, val, depth, curDepth + 1);        
            }
        }
        
        return root;
    }
};
