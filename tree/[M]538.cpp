// 538. Convert BST to Greater Tree - Medium
// https://leetcode.com/problems/convert-bst-to-greater-tree/

/* Analysis:
- Because it's a BST, we can visit nodes in decreasing order using inorder traversal from right to left.
- We use a variable "sum" to save sum of greater values, add it to the current node and update the "sum" to the value of current node after added.
- I implemented this idea using 2 ways, please choose what solution you like.
- Time complexity: O(n)
- Space complexity: O(1)
*/

// Solution 1:
class Solution {
public:
    int inorder(TreeNode *u, int greaterSum) {
        if (u == nullptr) {
            return greaterSum;
        }
        
        u->val += inorder(u->right, greaterSum);
        return inorder(u->left, u->val);
    }
    TreeNode* convertBST(TreeNode* root) {
        inorder(root, 0);
        return root;
    }
};

// Solution 2:
class Solution {
public:
    void inorder(TreeNode *u, int &greaterSum) {
        if (u == nullptr) {
            return ;
        }
        
        inorder(u->right, greaterSum);
        
        u->val += greaterSum;
        greaterSum = u->val;
        
        inorder(u->left, greaterSum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int greaterSum = 0;
        inorder(root, greaterSum);
        return root;
    }
};
