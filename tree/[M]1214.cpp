// https://leetcode.com/problems/two-sum-bsts/

/* O day ta co the luu 1 cay vao 1 hash table roi tim kiem tu cay con lai voi O(m + n).
- Hoac duoi 2 cay ra, roi dung 2 pointers tren 2 cay.
- Tuy nhien, anh thu lam cach nay cho quen tay.

*/

class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if (root1 == nullptr) {
            return false;
        }
        
        return find(root2, root1->val, target) || twoSumBSTs(root1->left, root2, target) || twoSumBSTs(root1->right, root2, target);
    }
    
    bool find(TreeNode *u, int firstVal, int target) {
        if (u == nullptr) {
            return false;
        }
        
        if (u->val + firstVal == target) {
            return true;
        } else if (u->val + firstVal > target) {
            return find(u->left, firstVal, target);
        } else {
            return find(u->right, firstVal, target);
        }
    }
};
