// 1424. Diagonal Traverse II - Medium
// https://leetcode.com/problems/diagonal-traverse-ii/

/* Analysis:
- We can list all integers following the diagonal order using BFS from position [0, 0].
- We push [0, 0] into the queue. For every item in queue, we add the below one first, then add the right one into queue.
- To avoid duplicate, we mark an added grid as negative.
- Time complexity: O(n * m)
- Space complexity: O(n * m)
*/

class Solution {
public:
    typedef pair<int, int> pii;
    bool valid(const vector<vector<int>>& nums, int i, int j) {
        return i < nums.size() && j < nums[i].size();
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pii> q;
        q.push({0, 0});
        nums[0][0] = -nums[0][0];
        
        vector<int> res;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            res.push_back(abs(nums[i][j]));
            
            int downi = i + 1, downj = j;
            if (valid(nums, downi, downj) && nums[downi][downj] > 0) {
                q.push({downi, downj});
                nums[downi][j] = -nums[downi][downj];
            }
            
            int righti = i, rightj = j + 1;
            if (valid(nums, righti, rightj) && nums[righti][rightj] > 0) {
                q.push({righti, rightj});
                nums[righti][rightj] = - nums[righti][rightj];
            }
        }
        return res;
    }
};
