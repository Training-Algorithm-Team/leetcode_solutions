// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

/* Ta co the duoi ra 1 sorted array roi dung 2 pointers.
- Tuy nhien, anh doc discussion va dung cach nay de on tap

*/ 

class Solution {
public:
    unordered_set<int> hash;
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) {
            return false;
        }
        if (hash.find(k - root->val) != hash.end()) {
            return true;
        }
        hash.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
