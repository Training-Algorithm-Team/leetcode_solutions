// 337. House Robber III - Medium
//https://leetcode.com/problems/house-robber-iii/

/* Analysis:
- I think this is kind of dp on true problem.
- We use dfs to traverse through the tree and calculate dp from the bottom to the root.
- At each node u, we return a pair of 2 value:
  + First: Maximum value we can rob at node u
  + Second: Maximum value we can rob at children nodes of u
- So the maximum value of u will be the maximum of 2 sums:
  + First values of 2 children
  + Second values of 2 children plus the current value of u
- Because we use dfs to the leaf, the children values will be calculated first then sum up to the root.
- Time complexity: O(n)
- Space complexity: O(n) for dfs stack.

*/

class Solution {
public:
    typedef pair<int, int> pii;
    pii dfs(TreeNode* u) {
        pii l, r;
        if (u->left) {
            l = dfs(u->left);
        }
        if (u->right) {
            r = dfs(u->right);
        }
        int cur = max(l.first + r.first, u->val + l.second + r.second);
        return make_pair(cur, l.first + r.first);
    }
    int rob(TreeNode* root) {
        return dfs(root).first;
    }
};
