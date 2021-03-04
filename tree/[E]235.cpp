// 235. Lowest Common Ancestor of a Binary Search Tree - Easy
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/* Solution 1:
- We build two stacks containing the parents of each node up to the root.
- After that, we balance the height of two stacks. We pop two stack until the top of 2 stacks are the same.
- Time complexity: O(log(n))
- Space complexity: O(log(n))
*/

class Solution {
public:
  
  void findNode(TreeNode *u, TreeNode *target, stack<TreeNode*> &res) {
    res.push(u);
    if (u == target) {
      return; 
    }
    if (u->val > target->val) {
      findNode(u->left, target, res); 
    } else {
      findNode(u->right, target, res);
    }
  }
  
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    stack<TreeNode*> stackP;
    findNode(root, p, stackP);
    
    stack<TreeNode*> stackQ;
    findNode(root, q, stackQ);
    
    while (stackP.size() > stackQ.size()) {
      stackP.pop(); 
    }
    while (stackQ.size() > stackP.size()) {
      stackQ.pop();
    }
    
    while (stackP.top() != stackQ.top()) {
      stackP.pop();
      stackQ.pop();
    }
    return stackP.top();
  }
};

/* Solution 2:
- In BST, the lowest common ancestor of 2 node has the value in between [p, q] inclusively (can be p or q itself).
- So, we keep traverse down the tree until we reach the range [p, q]. if, node u is on the left of the range, we move to the right child and vice versa.
- Time complexity: O(log(n))
- Space complexity: O(1)
*/

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *u = root;
    int left = min(p->val, q->val), right = max(p->val, q->val);
    while (u->val < left || u->val > right) {
      if (u->val < left) {
        u = u->right; 
      } else {
        u = u->left;
      }
    }
    return u;
  }
};
