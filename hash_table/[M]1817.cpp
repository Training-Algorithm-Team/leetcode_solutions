// 1817. Finding the Users Active Minutes - Medium
// https://leetcode.com/problems/finding-the-users-active-minutes/

/* Analysis:
- First, we build a hash table to know all distinct minutes per user.
- After that, we for through the hash table, for each user that has number of distinct minutes less than k, we increase the corresponding result by 1.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> uam;
        
        for (auto l : logs) {
            uam[l[0]].insert(l[1]);
        }
        
        vector<int> res(k, 0);
        for (auto &[user, actions] : uam) {
            if (actions.size() <= k) {
                res[actions.size() - 1]++;   
            }
        }
        
        return res;
    }
};
