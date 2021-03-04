// 108. Convert Sorted Array to Binary Search Tree - Easy
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/* Analysis:
- To make the height of two subtrees differs no more than one, we should choose the middle of the array to be the root of the tree
=> Number of nodes of 2 subtress differs no more than 1.
- After that, we have 2 smaller arrays to be converted to BST. We can do the previous task recursively until we reach the array with only 1 element.
- Time complexity: O(n). We choose each element 1 time to be 1 node in the BST.
- Space complexity: O(1). We dont have any intermediate storage.
*/

class Solution {
public:
  TreeNode* construct(const vector<int> &a, int l, int r) {
    if (l > r) {
      return nullptr; 
    }
    if (l == r) {
      return new TreeNode(a[l]); 
    }
    
    int mid = l + (r - l) / 2;
    TreeNode *u = new TreeNode(a[mid]);
    u->left = construct(a, l, mid - 1);
    u->right = construct(a, mid + 1, r);
    return u;
  }
  
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode *root = construct(nums, 0, nums.size() - 1);
    return root;
  }
};
