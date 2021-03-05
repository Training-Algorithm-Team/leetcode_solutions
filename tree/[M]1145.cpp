// 1145. Binary Tree Coloring Game - Medium
// https://leetcode.com/problems/binary-tree-coloring-game/

/* Analysis:
- If we think about x as a "center node" and it has 3 branches: left, right and up (go to parent node direction), whichever node we choose for y, it will stay on 
1 out of 3 branches, the y player cannot choose the nodes on the other 2 branches.
- So, the best node which player y can choose is that adjacent node to x and stays on the branch with largest number of node.
- We can count nodes in a tree recursively.
- For the up direction, we can count it by using (whole tree - (left subtree) - (right subtree))
- Time complexity: O(n)
- Space complexity: O(1).
*/

class Solution {
public:
    int countNodes(TreeNode *u) {
        if (u == nullptr) {
            return 0;
        }
        int res = 1;
        res += countNodes(u->left);
        res += countNodes(u->right);
        return res;
    }
    
    TreeNode* findNode(TreeNode *u, int x) {
        if (u == nullptr || u->val == x) {
            return u;
        }
        TreeNode *res = findNode(u->left, x);
        if (res != nullptr) {
            return res;
        }
        
        res = findNode(u->right, x);
        return res;
    }
    
    #define max(a, b, c) (a > b? (a > c? a : c) : (b > c? b : c))
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode *red = findNode(root, x);
        int l = countNodes(red->left);
        int r = countNodes(red->right);
        int u = n - l - r - 1;
        if (max(l, r, u) > n - max(l, r, u)) {
            return true;
        }
        return false;
    }
};
