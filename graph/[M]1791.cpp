// 1791. Find Center of Star Graph - Medium
// https://leetcode.com/problems/find-center-of-star-graph/

/* Analysis:
- A center node must appear in all edges. So we just need check to whether the node u or node v of an edge (u, v) is the center.
- We can check which node appear in another edge.
- Time complexity: O(1)
- Space complexity:O(1)
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int u1 = edges[0][0], v1 = edges[0][1], u2 = edges[1][0], v2 = edges[1][1];
        if (u1 == u2 || u1 == v2) {
            return u1;
        } else {
            return v1;
        }
    }
};
