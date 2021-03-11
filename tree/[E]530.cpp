// 530. Minimum Absolute Difference in BST - Easy
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

/* Analysis:
- If we visit the nodes in BST using inorder traversal and push them into an array, the array will be in ascending order.
- So we just need to calculate difference between adjacent elements in that array.
- In order to save space, we just need to save the previous element.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
    int minDiff = INT_MAX;
    int prev = -1;
    int getMinimumDifference(TreeNode* root) {
        if (!root) {
            return INT_MAX;
        }
        getMinimumDifference(root->left);
        
        minDiff = min(minDiff, prev < 0? INT_MAX: root->val - prev);
        prev = root->val;
        
        getMinimumDifference(root->right);
        return minDiff;
    }
};
