// 98. Validate Binary Search Tree - Medium
// https://leetcode.com/problems/validate-binary-search-tree/

/* Solution 1:
- For a BST, if we traverse it using inorder traversal, we will have an sorted increasing array. So we can traverse it inorderly and check the 
resulting array is increasing or not.
- However, to save space, we can just keep the previous value of the array and check whether the current value greater than the previous one.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
  bool inorder(TreeNode *u, long &prev) {
    if (!u) {
      return true; 
    }
    
    if (!inorder(u->left, prev)) {
      return false;
    }
    if (u->val <= prev) {
      return false; 
    }
    prev = u->val;
    if (!inorder(u->right, prev)) {
      return false;
    }
    return true;
  }
  bool isValidBST(TreeNode* root) {
    long prev = (long)INT_MIN - 1;
    return inorder(root, prev);
  }
};

/* Solution 2:
- For a valid BST, each node must be in a valid range. For the root, it maybe any number. 
- After that, for its left subtree, those nodes will be less than root, and right subtree's node will be greater than root. 
- So a node defines the boundary for the next nodes in its subtree. We can update the boundaries and check the validity of each node recursively.
- Time complexity: O(n)
- Space complexity: O(1)
*/
class Solution {
public:
  bool check(TreeNode *u, long l, long r) {
    if (u == nullptr) {
      return true; 
    }

    if (u->val < l || u->val > r) {
      return false;
    }
    return check(u->left, l, (long)u->val - 1) && check(u->right, (long)u->val + 1, r);    
  }
  
  bool isValidBST(TreeNode* root) {
    return check(root, (long)INT_MIN, (long)INT_MAX);
  }
};
