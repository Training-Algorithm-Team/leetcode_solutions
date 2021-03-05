// 1773. Count Items Matching a Rule - Easy
// https://leetcode.com/problems/count-items-matching-a-rule/

/* Analysis:
- We can for all items and check based on rule key and value.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int res = 0;
        for (auto &item : items) {
            if (ruleKey == "type" && item[0] == ruleValue) {
                res++;
            } else if (ruleKey == "color" && item[1] == ruleValue) {
                res++;
            } else if (ruleKey == "name" && item[2] == ruleValue) {
                res++;
            }
        }
        return res;
    }
};
