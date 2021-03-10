// 1080. Insufficient Nodes in Root to Leaf Paths - Medium
// https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/

/* Analysis:
- For a specific node, we recursively check the condition with it's childrent nodes. If a node is a child node and is an insufficient node, we notify to the parent
in order to delete (avoid memory leak) and set child to null.
- If that node does not have any sufficent children in the end, we notify this node is not a sufficent node to the parent.
- Time complexity: O(n)
- Space complexity: O(n) - worst case for call stack on a path tree.
*/

class Solution {
public:
    bool dfs(TreeNode *u, int sum, int limit) {
        if (u->left == nullptr && u->right == nullptr) {
            return sum + u->val >= limit;
        }
        
        bool sufficentLeft = false;
        if (u->left) {
            sufficentLeft = dfs(u->left, sum + u->val, limit);
            if (!sufficentLeft) {
                delete u->left;
                u->left = nullptr;
            }
        }
        
        bool sufficentRight = false; 
        if (u->right) {
            sufficentRight = dfs(u->right, sum + u->val, limit);
            if (!sufficentRight) {
                delete u->right;
                u->right = nullptr;
            }
        }
        
        return sufficentLeft || sufficentRight;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!dfs(root, 0, limit)) {
            return nullptr;   
        }
        return root;
    }
};
