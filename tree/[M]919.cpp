// 919. Complete Binary Tree Inserter - Medium
// https://leetcode.com/problems/complete-binary-tree-inserter/

/* Solution:
- A complete binary tree can be represented by an array, where the parent has index i, the left child has index (i * 2 + 1) and the right child has index (i * 2 + 2).
- So for the constructor, we can traverse through the whole tree and push them into the array using a temporary queue. We must do an extra work that is map the 
left and right child of parent into the real elements in the array.
- After that, we can insert new element into the back of the array and return the value of parent at index ((i - 1) / 2).
- Time complexity:
  + constructor: O(n)
  + insert: O(1)
  + getRoot: O(1)
 - Space complexity: O(n)
*/

class CBTInserter {
private:
    vector<TreeNode*> cbt;
public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* u = q.front();
            q.pop();
            cbt.push_back(u);
            
            if (u->left) {
                q.push(u->left);
            }
            if (u->right) {
                q.push(u->right);
            }
        }
        
        int n = cbt.size();
        for (int i = 0; i < n / 2; ++i) {
            cbt[i]->left = cbt[i * 2 + 1];
            if (i * 2 + 2 >= n) {
                break;
            }
            cbt[i]->right = cbt[i * 2 + 2];
        }
    }
    
    int insert(int v) {
        cbt.push_back(new TreeNode(v));
        int idx = cbt.size() - 1;
        int parent = (idx - 1) / 2;
        if (idx & 1) {
            cbt[parent]->left = cbt[idx];
        } else {
            cbt[parent]->right = cbt[idx];
        }
        return cbt[parent]->val;
    }
    
    TreeNode* get_root() {
        return cbt[0];
    }
};
